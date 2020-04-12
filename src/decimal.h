#ifndef H_D0E32AA72D1A43D0941D5D5A56FED376
#define H_D0E32AA72D1A43D0941D5D5A56FED376

#include <libmpdecpp_export.h>
#include <memory>
#include <string>
#include "roundmode.h"
#include "operations.h"
#include "scienfstringconversionformatflag.h"

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
      
      /** Convert Decimal value to string in scientifc notation.
       * @param format the format flag
       * @return the string representation of the Decimal value in sci notation.
       * @see SciEngStringConversionFormatFlag.
       */
      std::string toSciString( SciEngStringConversionFormatFlag format ) const;
      
      /** Convert Decimal to a string, using engineering notation if an exponent is needed.
       * Engineering notation has an exponent which is a multiple of 3. This can leave up to 3 
       * digits to the left of the decimal place and may require the addition of 
       * either one or two trailing zeros.
       * 
       *  For example, this converts Decimal('123E+1') to Decimal('1.23E+3').
       * 
       * @param format the format flag
       * @return the string representation of the Decimal value in eng notation.
       * @see SciEngStringConversionFormatFlag.
       */
      std::string toEngString( SciEngStringConversionFormatFlag format ) const;
      
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
      
      /** Convert Decimal to an uint32_t.
       * Converts the Decimal value to an uint32_t, no rounding is applied.
       * If type is not convertable, for exmple it is a negative number, then
       * an expetion is thrown.
       * @return the converted value.
       */
      uint32_t toUInt32() const;
      
      /** Convert Decimal to an uint64_t.
       * Converts the Decimal value to an uint64_t, no rounding is applied.
       * If type is not convertable, for exmple it is a negative number, then
       * an expetion is thrown.
       * @return the converted value.
       */
      uint64_t toUInt64() const;
      
      /** Multiplication assignment operator.
       * Multiply current Decimal value with other value and
       * assign result to this.
       * @param other other Decimal value.
       * @return Reference to this.
       */
      Decimal &operator*=( const mpdecimal::Decimal &other );
      
      /** Addition assignment operator.
       * Add other Decimal value from this one and assign result to this.
       * @param other other Decimal value.
       * @return Reference to this.
       */
      Decimal &operator+=( const mpdecimal::Decimal &other );
      
      /** Pre increment operation.
       * Increment Decimal value and return result.
       * @return Reference to this.
       */
      Decimal &operator++();
      
      /** Post increment operation.
       * Return copy of this before increment and increment this Decimal value.
       * @return Copy before increment.
       */
      Decimal operator++( int );
      
      /** Subtraction assignment operator.
       * Subtract other Decimal value from this and assign result to this.
       * @param other other Decimal value.
       * @return Reference to this.
       */
      Decimal &operator-=( const mpdecimal::Decimal &other );
      
      /** Pre decrement operation.
       * Decrement Decimal value and return result.
       * @return Reference to this.
       */
      Decimal &operator--();
      
      /** Post decrement operation.
       * Return copy of this before decrement and decrement Decimal value.
       * @return Copy before decrement.
       */
      Decimal operator--( int );
      
      /** Divide assignment operator.
       * Divide other Decimal value with this value and assign result to this.
       * @param other other Decimal value.
       * @return Reference to this.
       */
      Decimal &operator/=( const mpdecimal::Decimal &other );
      
      /** Divide mod assignment operator.
       * Use modulo operation of this and other Decimal and assign the result to this
       * @param other other Decimal value.
       * @return Reference to this.
       */
      Decimal &operator%=( const mpdecimal::Decimal &other );
      
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
      friend Decimal remainderNear( const Decimal &lhs, const Decimal &rhs );
      friend Decimal exp( const Decimal &value );
      friend Decimal ln( const Decimal &value );
      friend Decimal log( const Decimal &value );
      friend Decimal pow( const Decimal &base, const Decimal &exp );
      friend Decimal sqrt( const Decimal &value );
      friend Decimal abs( const Decimal &value );
      friend Decimal operator-( const Decimal &value );
      friend Decimal operator+( const Decimal &value );
      friend Decimal nextMinus( const Decimal &value );
      
    private:
      std::unique_ptr<detail::DecimalPrivate> m_private;
  };
}

#endif // H_D0E32AA72D1A43D0941D5D5A56FED376
