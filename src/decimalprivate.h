#ifndef H_61C5A137BF3142709EE274715BE7EC2F
#define H_61C5A137BF3142709EE274715BE7EC2F

#include "mpdecimalnamespace.h"
#include "decimaltypes.h"
#include "libmpdecpp_export.h"
#include "roundmode.h"
#include "scienfstringconversionformatflag.h"

MPDECIMAL_NAMESPACE_BEGIN

namespace detail
{  
  struct LIBMPDECPP_NO_EXPORT DecimalPrivate
  {
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
}

MPDECIMAL_NAMESPACE_END


#endif // H_61C5A137BF3142709EE274715BE7EC2F
