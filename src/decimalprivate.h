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
    
    std::string statusFlags() const;
    
    void resetStatus();
    
    mpd_context_t context;
    MPDDecimalPointer mpdDecimal;
    
    static mpd_ssize_t precision;
    static mpd_context_t defaultContext;
    
    static constexpr unsigned int charBufferSize = 1000;
  };
}

MPDECIMAL_NAMESPACE_END


#endif // U7F2A1D3DA63FF81E326BB20CE6F618F8
