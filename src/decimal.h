#ifndef U82ED56306C020E36CB5D80FFF178BA63
#define U82ED56306C020E36CB5D80FFF178BA63

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
      
      static void decimalInit( std::size_t precision );
      
    private:
      std::unique_ptr<detail::DecimalPrivate> m_private;
  };
}

#endif // U82ED56306C020E36CB5D80FFF178BA63
