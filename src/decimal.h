#ifndef U82ED56306C020E36CB5D80FFF178BA63
#define U82ED56306C020E36CB5D80FFF178BA63

#include <libmpdecpp_export.h>
#include <memory>
#include <string>
#include "roundmode.h"
#include "operations.h"

namespace mpdecimal
{
  namespace detail 
  {
    struct DecimalPrivate;
  }
  
  class LIBMPDECPP_EXPORT Decimal
  {
    public:
      /** Construct Decimal initialized with 0.
       * Construct a decimal with a zero value.
       */
      Decimal();
      
      /** Copy constructor.
       * Construct Decimal from another decimal.
       * @param other other Decimal value.
       */
      Decimal( const Decimal &other );
      
      /** Move constructor.
       * Move other Decimal value to this instance.
       * @param other other Decimal which will be moved.
       */
      Decimal( Decimal &&other );
      
      /** Init Decimal from an int32_t.
       * Constructor for int32_t initialisation.
       * @param value value used for initalizsation.
       */
      Decimal( int32_t value );
      
      /** Init Decimal from an int64_t.
       * Constructor for int64_t initialisation.
       * @param value value used for initalizsation.
       */
      Decimal( int64_t value );
      
      /** Init Decimal from an uint32_t.
       * Constructor for uint32_t initialisation.
       * @param value value used for initalizsation.
       */
      Decimal( uint32_t value );
      
      /** Init Decimal from an uint64_t.
       * Constructor for uint64_t initialisation.
       * @param value value used for initalizsation.
       */
      Decimal( uint64_t value );
      
      /** Init Decimal from a string.
       * Constructor for string initialisation.
       * @param value value used for initalizsation.
       */
      Decimal( const std::string &value );
      
      /** Init Decimal from c string.
       * Constructor for cstring initalisation.
       */
      Decimal( const char *value );
      
      /** Destructor.
       * Removes internal data structures of mpdecimal.
       */
      ~Decimal();
      
      
      /** Copy assign operator.
       * Assigns the value of the given Decimal.
       * @param other other Decimal value.
       */
      Decimal &operator=( const Decimal &other );
      
      /** Copy move assign operator.
       * Moves the value of the other Decimal value to this.
       * The other Decimal is afterwards initialized with 0.
       * @param other the other Decimal value.
       */
      Decimal &operator=( Decimal &&other );
      
      /** Convert Decimal value to string with rounding.
       * Converts the Decimal value to a string with respect of the default rounding mode.
       * @param precision the number of digits to round to.
       * @param roundMode the used round mode, if default is used the round mode from decimalInit is used.
       * @return the string representation of the Decimal value.
       */
      std::string toString( unsigned int precision, 
                            RoundMode roundMode = RoundMode::Default ) const;
                            
      /** Convert Decimal value to string with rounding.
       * Converts the Decimal value to a string with respect of the default rounding mode.
       * @param roundMode the used round mode, if default is used the round mode from decimalInit is used.
       * @return the string representation of the Decimal value.
       */
      std::string toString( RoundMode roundMode = RoundMode::Default ) const;
      
      /** Convert Decimal to an int32_t.
       * Converts the Decimal value to an int32_t, no rounding is applied.
       * If type is not convertable, for exmple it is a floating point, then
       * an expetion is thrown.
       * @return the converted value.
       */
      int32_t toInt32() const;
      
      /** Convert Decimal to an int64_t.
       * Converts the Decimal value to an int64_t, no rounding is applied.
       * If type is not convertable, for exmple it is a floating point, then
       * an expetion is thrown.
       * @return the converted value.
       */
      int64_t toInt64() const;
      
      
      uint32_t toUInt32() const;
      uint64_t toUInt64() const;
      
      /** Intialize library default settings.
       * Call this functions one time at program start to initialize Decimal
       * library and set some default settings.
       * @param precision The precision for all generated Decimal types.
       * @param defaultRoundMode set default round mode, default is RoundHalfEven.
       */
      static void decimalInit( std::size_t precision, 
                               RoundMode defaultRoundMode = RoundMode::RoundHalfEven );
      
      friend bool operator==( const Decimal &lhs, const Decimal &rhs );
      friend bool operator<( const Decimal &lhs, const Decimal &rhs );
      friend bool operator>( const Decimal &lhs, const Decimal &rhs );
      
    private:
      std::unique_ptr<detail::DecimalPrivate> m_private;
  };
}

#endif // U82ED56306C020E36CB5D80FFF178BA63
