#ifndef U82ED56306C020E36CB5D80FFF178BA63
#define U82ED56306C020E36CB5D80FFF178BA63

#include <libmpdecpp_export.h>
#include <memory>
#include <string>
#include "roundmode.h"

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
      
      /** Init decimal from an int32_t.
       * Constructor for int32_t initialisation.
       * @param value value used for initalizsation.
       */
      Decimal( int32_t value );
      
      /** Init decimal from an int64_t.
       * Constructor for int64_t initialisation.
       * @param value value used for initalizsation.
       */
      Decimal( int64_t value );
      
      /** Init decimal from an uint32_t.
       * Constructor for uint32_t initialisation.
       * @param value value used for initalizsation.
       */
      Decimal( uint32_t value );
      
      /** Init decimal from an uint64_t.
       * Constructor for uint64_t initialisation.
       * @param value value used for initalizsation.
       */
      Decimal( uint64_t value );
      
      /** Init decimal from a string.
       * Constructor for string initialisation.
       * @param value value used for initalizsation.
       */
      Decimal( const std::string &value );
      
      /** Destructor.
       * Removes internal data structures of mpdecimal.
       */
      ~Decimal();
      
      
      /** Copy assign operator.
       * Assigns the value of the given decimal.
       * @param other other decimal value.
       */
      Decimal &operator=( const Decimal &other );
      
      /** Copy move assign operator.
       * Moves the value of the other decimal value to this.
       * The other decimal is afterwards initialized with 0.
       * @param other the other decimal value.
       */
      Decimal &operator=( Decimal &&other );
      
      std::string toString( unsigned int precision ) const; // TODO Rounding
      std::string toString() const;
      
      /** Equality comparision operator.
       * Compares this decimal to ohter value.
       * @param other other decimal value for comparion.
       * @return True if other decimal value is equal this decimal value.
       */
      bool operator==( const Decimal &other );
      
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
