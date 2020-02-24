#ifndef H_E3F615B483B54E9488FC4CE6F08D791E
#define H_E3F615B483B54E9488FC4CE6F08D791E

#include "libmpdecpp_export.h"

namespace mpdecimal
{

  class Decimal;

  /** Equality comparision operator.
  * Compares to Decimal values on equality
  * @param other other decimal value for comparion.
  * @return True if other decimal value is equal this decimal value.
  */
  LIBMPDECPP_EXPORT bool operator==( const Decimal &lhs, const Decimal &rhs );
}

#endif // H_E3F615B483B54E9488FC4CE6F08D791E
