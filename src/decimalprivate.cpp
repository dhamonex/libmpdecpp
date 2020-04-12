#include "decimalprivate.h"

#include <boost/throw_exception.hpp>
#include <boost/lexical_cast.hpp>

#define CHECK_MPD_SET_STATUS \
    CHECK_DECIMAL_OPERATION( "Could not set decimal from value: " + boost::lexical_cast<std::string>( value ) )
  
#define CHECK_INTEGER_CONVERT \
    CHECK_DECIMAL_OPERATION( "Could not convert to integer value" )

MPDECIMAL_NAMESPACE_BEGIN

namespace detail
{
  struct RoundModeGuard
  {
    RoundModeGuard( mpd_context_t *context, RoundMode roundMode )
      : guardContext{ context },
        resetRoundMode{ false }
    {
      if ( roundMode != RoundMode::Default ) {
        DecimalPrivate::setContextRoundMode( guardContext, roundMode );
        resetRoundMode = true;
      }
    }
    
    ~RoundModeGuard()
    {
      if ( resetRoundMode ) {
        DecimalPrivate::setContextRoundMode( guardContext, DecimalPrivate::defaultRoundMode );
      }
    }
    
    mpd_context_t *guardContext;
    bool resetRoundMode;
  };
  
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
      case RoundMode::Default:        context->round = MPD_ROUND_HALF_EVEN; break;
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
    mpd_status_t status{ 0 };
    if ( !mpd_qcopy( mpdDecimal.get(), other.mpdDecimal.get(), &status ) ) {
      BOOST_THROW_EXCEPTION( DecimalException() 
        << ErrorString( "Could not copy decimal value" )
        << ErrorCode( status )
        << StatusFlags( statusFlags( status ) ) );
    }
    
  }
  
  void DecimalPrivate::setDecNumberValue( int32_t value )
  {
    mpd_status_t status{ 0 };
    mpd_qset_i32( mpdDecimal.get(), value, threadLocalContext(), &status );
    CHECK_MPD_SET_STATUS
  }
  
  void DecimalPrivate::setDecNumberValue( int64_t value )
  {
    mpd_status_t status{ 0 };
    mpd_qset_i64( mpdDecimal.get(), value, threadLocalContext(), &status );
    CHECK_MPD_SET_STATUS
  }
  
  void DecimalPrivate::setDecNumberValue( uint32_t value )
  {
    mpd_status_t status{ 0 };
    mpd_qset_u32( mpdDecimal.get(), value, threadLocalContext(), &status );
    CHECK_MPD_SET_STATUS
  }
  
  void DecimalPrivate::setDecNumberValue( uint64_t value )
  {
    mpd_status_t status{ 0 };
    mpd_qset_u64( mpdDecimal.get(), value, threadLocalContext(), &status );
    CHECK_MPD_SET_STATUS
  }
  
  void DecimalPrivate::setDecNumberValue( std::string_view value )
  {
    mpd_status_t status{ 0 };
    mpd_qset_string( mpdDecimal.get(), value.data(), threadLocalContext(), &status );
    CHECK_MPD_SET_STATUS
  }
  
  ComparisonResult DecimalPrivate::compareToOtherValue( const DecimalPrivate &other )
  {
    [[maybe_unused]] auto result = createDecimal();
    mpd_status_t status{ 0 };
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
  
  void DecimalPrivate::multiplyAssign( const DecimalPrivate &other )
  {
    applyMpdecimalOperation( &mpd_qmul, ErrorCheckMode::Default, "Multiply failed ({} * {})", other );
  }
  
  void DecimalPrivate::divideAssign( const DecimalPrivate &other )
  {
    applyMpdecimalOperation( &mpd_qdiv, ErrorCheckMode::Default, "Divide failed ({} / {})", other );
  }
  
  void DecimalPrivate::addAssign( const DecimalPrivate &other )
  {
    applyMpdecimalOperation( &mpd_qadd, ErrorCheckMode::Default, "Addition failed ({} + {})", other );
  }
  
  void DecimalPrivate::subtractAssing( const DecimalPrivate &other )
  {
    applyMpdecimalOperation( &mpd_qsub, ErrorCheckMode::Default, "Subtraction failed ({} - {})", other );
  }
  
  void DecimalPrivate::divideModAssign( const DecimalPrivate &other )
  {
    applyMpdecimalOperation( &mpd_qrem, ErrorCheckMode::Default, "Remainder failed ({} qrem {})", other );
  }
  
  void DecimalPrivate::remainderNearAssign( const DecimalPrivate &other )
  {
    applyMpdecimalOperation( &mpd_qrem_near, ErrorCheckMode::Default, "Remainder-Near failed ({} remnear {})", other );
  }
  
  void DecimalPrivate::expAndAssign()
  {
    applyMpdecimalOperation( &mpd_qexp, ErrorCheckMode::IgnoreInexactRounding, "Exp failed ({})" );
  }
  
  void DecimalPrivate::lnAndAssign()
  {
    applyMpdecimalOperation( &mpd_qln, ErrorCheckMode::IgnoreInexactRounding, "LN failed({})" );
  }
  
  void DecimalPrivate::log10AndAssign()
  {
    applyMpdecimalOperation( &mpd_qlog10, ErrorCheckMode::IgnoreInexactRounding, "Log of base 10 failed ({})" );
  }
  
  void DecimalPrivate::powAndAssign( const DecimalPrivate &exp )
  {
    applyMpdecimalOperation( &mpd_qpow, ErrorCheckMode::Default, "pow operation failed ({} ** {})", exp );
  }
  
  void DecimalPrivate::sqrtAndAssign()
  {
    applyMpdecimalOperation( &mpd_qsqrt, ErrorCheckMode::IgnoreInexactRounding, "sqrt operation failed ({})" );
  }
  
  void DecimalPrivate::abs()
  {
    applyMpdecimalOperation( &mpd_qabs, ErrorCheckMode::Default, "abs() operation on {} failed." );
  }
  
  void DecimalPrivate::minusAssign()
  {
    applyMpdecimalOperation( &mpd_qminus, ErrorCheckMode::Default, "minus operation on {} failed." );
  }
  
  void DecimalPrivate::plusAssign()
  {
    applyMpdecimalOperation( &mpd_qplus, ErrorCheckMode::Default, "Plus operation on {} failed." );
  }
  
  std::string DecimalPrivate::toString( RoundMode roundMode ) const
  {
    return toString( "f", roundMode );
  }
  
  std::string DecimalPrivate::toString( unsigned int precision, RoundMode roundMode ) const
  {
    return toString( "." + boost::lexical_cast<std::string>( precision ) + "f", roundMode );
  }
  
  std::string DecimalPrivate::toString( const std::string &format, RoundMode roundMode ) const
  {
    mpd_status_t status{ 0 };
    RoundModeGuard roundModeGuard( threadLocalContext(), roundMode );
    
    MPDecimalCharPointer result( mpd_qformat( mpdDecimal.get(), format.c_str(), roundModeGuard.guardContext, &status ) );
    
    if ( status != 0 ) {
      BOOST_THROW_EXCEPTION( DecimalException() 
        << ErrorString( "Could not format decimal value with format " + format )
        << ErrorCode( status )
        << StatusFlags( statusFlags( status ) ) );
    }
    
    return result.get();
  }
  
  std::string DecimalPrivate::toSciString( SciEngStringConversionFormatFlag format ) const
  {
    MPDecimalCharPointer result( mpd_to_sci( mpdDecimal.get(), convertFormatFlag( format ) ) );
    return result.get();
  }
  
  std::string DecimalPrivate::toEngString( SciEngStringConversionFormatFlag format ) const
  {
    MPDecimalCharPointer result( mpd_to_eng( mpdDecimal.get(), convertFormatFlag( format ) ) );
    return result.get();
  }
  
  int32_t DecimalPrivate::toInt32() const
  {
    mpd_status_t status{ 0 };
    int32_t result = mpd_qget_i32( mpdDecimal.get(), &status );
    
    CHECK_INTEGER_CONVERT
    
    return result;
  }
  
  int64_t DecimalPrivate::toInt64() const
  {
    mpd_status_t status{ 0 };
    int64_t result = mpd_qget_i64( mpdDecimal.get(), &status );
    
    CHECK_INTEGER_CONVERT
    
    return result;
  }
 
  uint32_t DecimalPrivate::toUInt32() const
  {
    mpd_status_t status{ 0 };
    uint32_t result = mpd_qget_u32( mpdDecimal.get(), &status );
    
    CHECK_INTEGER_CONVERT
    
    return result;
  }
  
  uint64_t DecimalPrivate::toUInt64() const
  {
    mpd_status_t status{ 0 };
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
  
  constexpr int DecimalPrivate::convertFormatFlag( SciEngStringConversionFormatFlag format )
  {
    if ( format == SciEngStringConversionFormatFlag::LowerCaseExponentCharacter ) {
      return 0;
    }
    
    return 1;
  }
}

MPDECIMAL_NAMESPACE_END
