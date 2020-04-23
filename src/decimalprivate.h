#ifndef H_61C5A137BF3142709EE274715BE7EC2F
#define H_61C5A137BF3142709EE274715BE7EC2F

#include <fmt/format.h>

#include "decimalexceptions.h"
#include "decimaltypes.h"
#include "errorchecks.h"
#include "libmpdecpp_export.h"
#include "mpdecimalnamespace.h"
#include "roundmode.h"
#include "scienfstringconversionformatflag.h"

MPDECIMAL_NAMESPACE_BEGIN

namespace detail
{
  struct LIBMPDECPP_NO_EXPORT DecimalPrivate
  {
    enum class ErrorCheckMode
    {
      Default,
      IgnoreInexactRounding
    };

    DecimalPrivate();

    DecimalPrivate( const DecimalPrivate &other );

    void setDecNumberValue( int32_t value );
    void setDecNumberValue( int64_t value );
    void setDecNumberValue( uint32_t value );
    void setDecNumberValue( uint64_t value );
    void setDecNumberValue( std::string_view value );

    std::string toString( RoundMode roundMode ) const;
    std::string toString( unsigned int precision, RoundMode roundMode ) const;
    std::string toString( const std::string &format, RoundMode roundMode ) const;
    std::string toSciString( SciEngStringConversionFormatFlag format ) const;
    std::string toEngString( SciEngStringConversionFormatFlag format ) const;

    int32_t toInt32() const;
    int64_t toInt64() const;
    uint32_t toUInt32() const;
    uint64_t toUInt64() const;

    ComparisonResult compareToOtherValue( const DecimalPrivate &other );

    void multiplyAssign( const DecimalPrivate &other );
    void divideAssign( const DecimalPrivate &other );
    void addAssign( const DecimalPrivate &other );
    void subtractAssing( const DecimalPrivate &other );
    void remainderNearAssign( const DecimalPrivate &other );
    void divideModAssign( const DecimalPrivate &other );
    void expAndAssign();
    void lnAndAssign();
    void log10AndAssign();
    void powAndAssign( const DecimalPrivate &exp );
    void sqrtAndAssign();
    void abs();
    void minusAssign();
    void plusAssign();
    void nextMinusAssign();
    void nextPlusAssing();
    void nextTowardAssign( const DecimalPrivate &other );
    void quantizeAssign( const DecimalPrivate &other );
    void floorAssign();
    void ceilAssign();

    template <typename F, class... Args>
    void applyMpdecimalOperation( F function, DecimalPrivate::ErrorCheckMode checkMode,
                                  std::string_view errorMessageFormat, Args &&... args );

    MPDDecimalPointer mpdDecimal;

    static MPDDecimalPointer createDecimal();

    static mpd_context_t *threadLocalContext();
    static void setContextRoundMode( mpd_context_t *context, RoundMode roundMode );

    static std::string statusFlags( uint32_t status );

    static constexpr int convertFormatFlag( SciEngStringConversionFormatFlag format );

    static inline mpd_ssize_t precision = 0;
    static inline mpd_context_t defaultContext;
    static inline RoundMode defaultRoundMode = RoundMode::Default;

    static constexpr unsigned int charBufferSize = 1000;
  };

  inline std::string getString( const DecimalPrivate &decimal )
  {
    return decimal.toString( RoundMode::Default );
  }

  inline const mpd_t *expandDecimalPointer( const DecimalPrivate &decimal )
  {
    return decimal.mpdDecimal.get();
  }

  template <typename F, class... Args>
  void
  DecimalPrivate::applyMpdecimalOperation( F function, DecimalPrivate::ErrorCheckMode checkMode,
                                           std::string_view errorMessageFormat, Args &&... args )
  {
    auto result = DecimalPrivate::createDecimal();
    mpd_status_t status{ 0 };

    function( result.get(), expandDecimalPointer( *this ), expandDecimalPointer( args )...,
              DecimalPrivate::threadLocalContext(), &status );

    if ( checkMode == DecimalPrivate::ErrorCheckMode::IgnoreInexactRounding ) {
#if FMT_VERSION >= 60000
      CHECK_DECIMAL_OPERATION_IGNORE_INEXACT_VALUE(
        fmt::format( errorMessageFormat, getString( *this ), getString( args )... ) );
#else
      CHECK_DECIMAL_OPERATION_IGNORE_INEXACT_VALUE( fmt::format(
        std::string( errorMessageFormat ), getString( *this ), getString( args )... ) );
#endif

    } else {
#if FMT_VERSION >= 60000
      CHECK_DECIMAL_OPERATION(
        fmt::format( errorMessageFormat, getString( *this ), getString( args )... ) );
#else
      CHECK_DECIMAL_OPERATION( fmt::format( std::string( errorMessageFormat ), getString( *this ),
                                            getString( args )... ) );
#endif
    }

    std::swap( mpdDecimal, result );
  }
} // namespace detail

MPDECIMAL_NAMESPACE_END

#endif // H_61C5A137BF3142709EE274715BE7EC2F
