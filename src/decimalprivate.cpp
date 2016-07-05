#include "decimalprivate.h"
#include "decimalexceptions.h"

#include <boost/throw_exception.hpp>
#include <boost/lexical_cast.hpp>

#define CHECK_MPD_SET_STATUS \
    if ( status != 0 ) { \
      BOOST_THROW_EXCEPTION( DecimalException() \
        << ErrorString( "Could not set decimal from value: " + boost::lexical_cast<std::string>( value ) ) \
        << ErrorCode( status ) << StatusFlags( statusFlags( status ) ) ); \
    }
  
#define CHECK_INTEGER_CONVERT \
    if ( status != 0 ) { \
      BOOST_THROW_EXCEPTION( DecimalException() \
        << ErrorString( "Could not convert to integer value" ) \
        << ErrorCode( status ) \
        << StatusFlags( statusFlags( status ) ) ); \
    }

MPDECIMAL_NAMESPACE_BEGIN

namespace detail
{
  mpd_ssize_t DecimalPrivate::precision = 0;
  mpd_context_t DecimalPrivate::defaultContext; 
  
  DecimalPrivate::DecimalPrivate()
    : mpdDecimal()
  {
    if ( precision == 0 ) {
      BOOST_THROW_EXCEPTION( NotInitialized() 
        << ErrorString( "Decimal not initialized. Use Decimal::decimalInit to set precition and initialize decimal library" ) );
    }
    
    mpdDecimal.reset( mpd_qnew() );
    if ( !mpdDecimal ) {
      BOOST_THROW_EXCEPTION( DecimalException() << ErrorString( "Could not create new decimal" ) );
    }
    
    setDecNumberValue( 0 );
  }
  
  void DecimalPrivate::setDecNumberValue( int32_t value )
  {
    uint32_t status = 0;
    mpd_qset_i32( mpdDecimal.get(), value, &defaultContext, &status );
    CHECK_MPD_SET_STATUS
  }
  
  void DecimalPrivate::setDecNumberValue( int64_t value )
  {
    uint32_t status = 0;
    mpd_qset_i64( mpdDecimal.get(), value, &defaultContext, &status );
    CHECK_MPD_SET_STATUS
  }
  
  void DecimalPrivate::setDecNumberValue( uint32_t value )
  {
    uint32_t status = 0;
    mpd_qset_u32( mpdDecimal.get(), value, &defaultContext, &status );
    CHECK_MPD_SET_STATUS
  }
  
  void DecimalPrivate::setDecNumberValue( uint64_t value )
  {
    uint32_t status = 0;
    mpd_qset_u64( mpdDecimal.get(), value, &defaultContext, &status );
    CHECK_MPD_SET_STATUS
  }
  
  void DecimalPrivate::setDecNumberValue( const std::string &value )
  {
    uint32_t status = 0;
    mpd_qset_string( mpdDecimal.get(), value.c_str(), &defaultContext, &status );
    CHECK_MPD_SET_STATUS
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
    MPDecimalCharPointer result( mpd_qformat( mpdDecimal.get(), format.c_str(), &defaultContext, &status ) );
    
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
  
  std::string DecimalPrivate::statusFlags( uint32_t status )
  {
    char buffer[charBufferSize];
    mpd_snprint_flags( buffer, charBufferSize, status );
    
    return buffer;
  }
}

MPDECIMAL_NAMESPACE_END
