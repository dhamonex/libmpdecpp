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
      explicit Decimal( double value );
      explicit Decimal( int32_t value );
      explicit Decimal( int64_t value );
      explicit Decimal( uint32_t value );
      explicit Decimal( uint64_t value );
      explicit Decimal( const std::string &value );
      
      ~Decimal();
      
      explicit Decimal( const Decimal &other );
      Decimal &operator=( const Decimal &other );
      
      std::string toString( unsigned int precision ) const;
      std::string toString() const;
      
      static void decimalInit( std::size_t precision );
      
    private:
      std::unique_ptr<detail::DecimalPrivate> m_private;
  };
}

#endif // U82ED56306C020E36CB5D80FFF178BA63
