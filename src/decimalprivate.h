#ifndef U7F2A1D3DA63FF81E326BB20CE6F618F8
#define U7F2A1D3DA63FF81E326BB20CE6F618F8

#include "mpdecimalnamespace.h"
#include "decimaltypes.h"
#include "libmpdecimal_export.h"

MPDECIMAL_NAMESPACE_BEGIN

namespace detail
{
  struct LIBMPDECIMAL_NO_EXPORT DecimalPrivate
  {
    DecimalPrivate();
    
    DecimalPrivate( const DecimalPrivate &other );
    
    void createDecimal();

    void setDecNumberValue( int32_t value );
    void setDecNumberValue( int64_t value );
    void setDecNumberValue( uint32_t value );
    void setDecNumberValue( uint64_t value );
    void setDecNumberValue( const std::string &value );
    
    std::string toString() const;
    std::string toString( unsigned int precision ) const;
    std::string toString( const std::string &format ) const;
    std::string toSciString( int fmt ) const;
    std::string toEngString( int fmt ) const;
    int32_t toInt32() const;
    int64_t toInt64() const;
    uint32_t toUInt32() const;
    uint64_t toUInt64() const;
    
    
    MPDDecimalPointer mpdDecimal;
    
    
    static std::string statusFlags( uint32_t status );
    
    static mpd_ssize_t precision;
    static mpd_context_t defaultContext;
    
    static constexpr unsigned int charBufferSize = 1000;
  };
}

MPDECIMAL_NAMESPACE_END


#endif // U7F2A1D3DA63FF81E326BB20CE6F618F8
