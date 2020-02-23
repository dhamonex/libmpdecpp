#include "decimalprivate.h"
#include "decimalexceptions.h"

#include <boost/throw_exception.hpp>
#include <boost/lexical_cast.hpp>

#define THROW_DECIMAL_EXCEPTION( message ) \
  BOOST_THROW_EXCEPTION( DecimalException() \
        << ErrorString( message ) \
        << ErrorCode( status ) \
        << StatusFlags( statusFlags( status ) ) )

#define CHECK_MPD_SET_STATUS \
    if ( status != 0 ) { \
      THROW_DECIMAL_EXCEPTION( "Could not set decimal from value: " + boost::lexical_cast<std::string>( value ) ); \
    }
  
#define CHECK_INTEGER_CONVERT \
    if ( status != 0 ) { \
      THROW_DECIMAL_EXCEPTION( "Could not convert to integer value" ); \
    }

MPDECIMAL_NAMESPACE_BEGIN

namespace detail
{
  mpd_ssize_t DecimalPrivate::precision = 0;
  mpd_context_t DecimalPrivate::defaultContext; 
  
  mpd_context_t *DecimalPrivate::threadLocalContext()
  {
    if ( precision == 0 ) {
      BOOST_THROW_EXCEPTION( NotInitialized() 
        << ErrorString( "Decimal not initialized. Use Decimal::decimalInit to set precition and initialize decimal library" ) );
    }
    
    thread_local mpd_context_t context{ defaultContext };
    return &context;
  }
  
  void DecimalPrivate::setContextRoundMode( mpd_context_t *context, RoundMode roundMode )
  {
    switch ( roundMode ) {
      case RoundMode::RoundUp:        context->round = MPD_ROUND_UP; break;
      case RoundMode::RoundDown:      context->round = MPD_ROUND_DOWN; break;
      case RoundMode::RoundCeiling:   context->round = MPD_ROUND_CEILING; break;
      case RoundMode::RoundFloor:     context->round = MPD_ROUND_FLOOR; break;
      case RoundMode::RoundHalfUp:    context->round = MPD_ROUND_HALF_UP; break;
      case RoundMode::RoundHalfDown:  context->round = MPD_ROUND_HALF_DOWN; break;
      case RoundMode::RoundHalfEven:  context->round = MPD_ROUND_HALF_EVEN; break;
      case RoundMode::Round05Up:      context->round = MPD_ROUND_05UP; break;
      case RoundMode::RoundTrunc:     context->round = MPD_ROUND_TRUNC; break;
    }
  }
  
  DecimalPrivate::DecimalPrivate()
    : mpdDecimal{ createDecimal() }
  {
    setDecNumberValue( 0 );
  }
  
  DecimalPrivate::DecimalPrivate( const DecimalPrivate &other )
    : mpdDecimal{ createDecimal() }
  {
    uint32_t status = 0;
    if ( !mpd_qcopy( mpdDecimal.get(), other.mpdDecimal.get(), &status ) ) {
      BOOST_THROW_EXCEPTION( DecimalException() 
        << ErrorString( "Could not copy decimal value" )
        << ErrorCode( status )
        << StatusFlags( statusFlags( status ) ) );
    }
    
  }
  
  void DecimalPrivate::setDecNumberValue( int32_t value )
  {
    mpd_status_t status = 0;
    mpd_qset_i32( mpdDecimal.get(), value, threadLocalContext(), &status );
    CHECK_MPD_SET_STATUS
  }
  
  void DecimalPrivate::setDecNumberValue( int64_t value )
  {
    mpd_status_t status = 0;
    mpd_qset_i64( mpdDecimal.get(), value, threadLocalContext(), &status );
    CHECK_MPD_SET_STATUS
  }
  
  void DecimalPrivate::setDecNumberValue( uint32_t value )
  {
    mpd_status_t status = 0;
    mpd_qset_u32( mpdDecimal.get(), value, threadLocalContext(), &status );
    CHECK_MPD_SET_STATUS
  }
  
  void DecimalPrivate::setDecNumberValue( uint64_t value )
  {
    mpd_status_t status = 0;
    mpd_qset_u64( mpdDecimal.get(), value, threadLocalContext(), &status );
    CHECK_MPD_SET_STATUS
  }
  
  void DecimalPrivate::setDecNumberValue( const std::string &value )
  {
    mpd_status_t status = 0;
    mpd_qset_string( mpdDecimal.get(), value.c_str(), threadLocalContext(), &status );
    CHECK_MPD_SET_STATUS
  }
  
  ComparisonResult DecimalPrivate::compareToOtherValue( const DecimalPrivate &other )
  {
    auto result = createDecimal();
    mpd_status_t status = 0;
    const auto cmpResult = mpd_qcompare_signal( result.get(), mpdDecimal.get(), other.mpdDecimal.get(), threadLocalContext(), &status );
    
    if ( status != 0 ) {
      THROW_DECIMAL_EXCEPTION( "Could not compare decimal values" );
    }
    
    if ( cmpResult > 0 ) {
      return ComparisonResult::Greater;
      
    } else if ( cmpResult < 0 ) {
      return ComparisonResult::Less;
    }
    
    return ComparisonResult::Equal;
  }
  
  std::string DecimalPrivate::toString() const
  {
    return toString( "f" );
  }
  
  std::string DecimalPrivate::toString( unsigned int precision ) const
  {
    return toString( "." + boost::lexical_cast<std::string>( precision ) + "f" );
  }
  
  std::string DecimalPrivate::toString( const std::string &format ) const
  {
    uint32_t status = 0;
    MPDecimalCharPointer result( mpd_qformat( mpdDecimal.get(), format.c_str(), threadLocalContext(), &status ) );
    
    if ( status != 0 ) {
      BOOST_THROW_EXCEPTION( DecimalException() 
        << ErrorString( "Could not format decimal value with format " + format )
        << ErrorCode( status )
        << StatusFlags( statusFlags( status ) ) );
    }
    
    return result.get();
  }
  
  std::string DecimalPrivate::toSciString( int fmt ) const
  {
    MPDecimalCharPointer result( mpd_to_sci( mpdDecimal.get(), fmt ) );
    return result.get();
  }
  
  std::string DecimalPrivate::toEngString( int fmt ) const
  {
    MPDecimalCharPointer result( mpd_to_eng( mpdDecimal.get(), fmt ) );
    return result.get();
  }
  
  int32_t DecimalPrivate::toInt32() const
  {
    uint32_t status = 0;
    int32_t result = mpd_qget_i32( mpdDecimal.get(), &status );
    
    CHECK_INTEGER_CONVERT
    
    return result;
  }
  
  int64_t DecimalPrivate::toInt64() const
  {
    uint32_t status = 0;
    int64_t result = mpd_qget_i64( mpdDecimal.get(), &status );
    
    CHECK_INTEGER_CONVERT
    
    return result;
  }
 
  uint32_t DecimalPrivate::toUInt32() const
  {
    uint32_t status = 0;
    uint32_t result = mpd_qget_u32( mpdDecimal.get(), &status );
    
    CHECK_INTEGER_CONVERT
    
    return result;
  }
  
  uint64_t DecimalPrivate::toUInt64() const
  {
    uint32_t status = 0;
    uint64_t result = mpd_qget_u64( mpdDecimal.get(), &status );
    
    CHECK_INTEGER_CONVERT
    
    return result;
  }
  
  MPDDecimalPointer DecimalPrivate::createDecimal()
  {
    MPDDecimalPointer mpdDecimal( mpd_qnew() );
    if ( !mpdDecimal ) {
      BOOST_THROW_EXCEPTION( DecimalException() << ErrorString( "Could not create new decimal" ) );
    }
    
    return mpdDecimal;
  }
  
  std::string DecimalPrivate::statusFlags( uint32_t status )
  {
    char buffer[charBufferSize];
    mpd_snprint_flags( buffer, charBufferSize, status );
    
    return buffer;
  }
}

MPDECIMAL_NAMESPACE_END
