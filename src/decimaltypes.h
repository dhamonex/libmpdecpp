#ifndef UE214BACCE6F9EFBD7683F7AE82B12670
#define UE214BACCE6F9EFBD7683F7AE82B12670

#include <memory>
#include <mpdecimal.h>

namespace mpdecimal
{
  namespace detail
  {
    struct MPDecimalDeleter
    {
      void operator()( mpd_t *decimal )
      {
        mpd_del( decimal );
      }
    };
    
    struct MPDecimalCharDeleter
    {
      void operator()( char *decimalString )
      {
        mpd_free( decimalString );
      }
    };
    
    using MPDDecimalPointer = std::unique_ptr<mpd_t, MPDecimalDeleter>;
    using MPDecimalCharPointer = std::unique_ptr<char[], MPDecimalCharDeleter>;
  }
}


#endif // UE214BACCE6F9EFBD7683F7AE82B12670
