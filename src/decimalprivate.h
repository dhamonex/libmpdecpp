#ifndef U7F2A1D3DA63FF81E326BB20CE6F618F8
#define U7F2A1D3DA63FF81E326BB20CE6F618F8

#include "mpdecimalnamespace.h"
#include "decimaltypes.h"
#include "libmpdecpp_export.h"
#include "roundmode.h"

MPDECIMAL_NAMESPACE_BEGIN

namespace detail
{
  enum class ComparisonResult
  {
    Less,
    Equal,
    Greater
  };
  
  using mpd_status_t = uint32_t;
  
  struct LIBMPDECPP_NO_EXPORT DecimalPrivate
  {
    DecimalPrivate();
    
    DecimalPrivate( const DecimalPrivate &other );

    void setDecNumberValue( int32_t value );
    void setDecNumberValue( int64_t value );
    void setDecNumberValue( uint32_t value );
    void setDecNumberValue( uint64_t value );
    void setDecNumberValue( std::string_view value );
    
    std::string toString() const;
    std::string toString( unsigned int precision ) const;
    std::string toString( const std::string &format ) const;
    std::string toSciString( int fmt ) const;
    std::string toEngString( int fmt ) const;
    int32_t toInt32() const;
    int64_t toInt64() const;
    uint32_t toUInt32() const;
    uint64_t toUInt64() const;
    
    ComparisonResult compareToOtherValue( const DecimalPrivate &other );
    
    MPDDecimalPointer mpdDecimal;
    
    static MPDDecimalPointer createDecimal();
    
    static mpd_context_t *threadLocalContext();
    static void setContextRoundMode( mpd_context_t *context, RoundMode roundMode );
    
    static std::string statusFlags( uint32_t status );
    
    static mpd_ssize_t precision;
    static mpd_context_t defaultContext;
    
    static constexpr unsigned int charBufferSize = 1000;
  };
}

MPDECIMAL_NAMESPACE_END


#endif // U7F2A1D3DA63FF81E326BB20CE6F618F8
