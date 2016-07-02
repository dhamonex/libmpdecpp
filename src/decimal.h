#include <libmpdecimal_export.h>
#include <memory>
#include <string>

namespace mpdecimal
{
  namespace detail 
  {
    struct DecimalPrivate;
  }
  
  class LIBMPDECIMAL_EXPORT Decimal
  {
    public:
      Decimal();
      Decimal( double value );
      Decimal( int32_t value );
      Decimal( int64_t value );
      Decimal( uint32_t value );
      Decimal( uint64_t value );
      Decimal( const std::string &value );
      
      ~Decimal();
      
      Decimal( const Decimal &other );
      Decimal &operator=( const Decimal &other );
      
    private:
      std::unique_ptr<detail::DecimalPrivate> m_private;
  };
}
