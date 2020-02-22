#ifndef U82ED56306C020E36CB5D80FFF178BA63
#define U82ED56306C020E36CB5D80FFF178BA63

#include <libmpdecpp_export.h>
#include <memory>
#include <string>

namespace mpdecimal
{
  namespace detail 
  {
    struct DecimalPrivate;
  }
  
  class LIBMPDECPP_EXPORT Decimal
  {
    public:
      Decimal();
      Decimal( const Decimal &other );
      
      explicit Decimal( double value );
      explicit Decimal( int32_t value );
      explicit Decimal( int64_t value );
      explicit Decimal( uint32_t value );
      explicit Decimal( uint64_t value );
      explicit Decimal( const std::string &value );
      
      ~Decimal();
      
      Decimal &operator=( const Decimal &other );
      
      std::string toString( unsigned int precision ) const;
      std::string toString() const;
      
      /** Intialize library default settings.
       * Call this functions one time at program start to initialize decimal
       * library and set some default settings.
       * @param precision The precision for all generated decimal types.
       * @param defaultRoundMode set default round mode, default is RoundHalfEven.
       */
      static void decimalInit( std::size_t precision, 
                               RoundMode defaultRoundMode = RoundMode::RoundHalfEven );
      
    private:
      std::unique_ptr<detail::DecimalPrivate> m_private;
  };
}

#endif // U82ED56306C020E36CB5D80FFF178BA63
