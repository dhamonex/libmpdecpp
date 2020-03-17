#ifndef H_E3F615B483B54E9488FC4CE6F08D791E
#define H_E3F615B483B54E9488FC4CE6F08D791E

#include "libmpdecpp_export.h"

namespace mpdecimal
{

  class Decimal;

  /** Equality comparision operator.
  * Compares two Decimal values on equality
  * @param lhs left hand side Decimal value.
  * @param rhs right hand side Decimal value.
  * @return True if other decimal value is equal this decimal value, false otherwise.
  */
  LIBMPDECPP_EXPORT bool operator==( const Decimal &lhs, const Decimal &rhs );
  
  /** Less than comparision operator.
  * Compares two Decimal values on and returns true if rhs is less than lhs
  * @param lhs left hand side decimal value.
  * @param rhs right hand side decimal value.
  * @return True if lhs is less than rhs, false otherwise.
  */
  LIBMPDECPP_EXPORT bool operator<( const Decimal &lhs, const Decimal &rhs );
  
  /** Less than or equal comparision operator.
  * Compares two Decimal values on and returns true if rhs is less or equal than lhs
  * @param lhs left hand side Decimal value.
  * @param rhs right hand side Decimal value.
  * @return True if lhs is less or equal than rhs, false otherwise.
  */
  LIBMPDECPP_EXPORT bool operator<=( const Decimal &lhs, const Decimal &rhs );
  
  /** Greater than comparision operator.
  * Compares two Decimal values on and returns true if rhs is greater than lhs
  * @param lhs left hand side Decimal value.
  * @param rhs right hand side Decimal value.
  * @return True if lhs is greater than rhs, false otherwiese.
  */
  LIBMPDECPP_EXPORT bool operator>( const Decimal &lhs, const Decimal &rhs );
  
  /** Greater than comparision operator.
  * Compares two Decimal values on and returns true if rhs is greater than lhs
  * @param lhs left hand side Decimal value.
  * @param rhs right hand side Decimal value.
  * @return True if lhs is greater than rhs, false otherwise.
  */
  LIBMPDECPP_EXPORT bool operator>=( const Decimal &lhs, const Decimal &rhs );
  
  /** Unequal comparision operator.
   * Compares two Decimal values and returns true if they are not equal.
   * @param lhs left hand side Decimal value.
   * @param rhs right hand side Decimal value.
   * @return True if lhs is not equal to rhs, false otherwise.
   */
  LIBMPDECPP_EXPORT bool operator!=( const Decimal &lhs, const Decimal &rhs );
  
  /** Multiply two Decimal values.
   * Multiply the given two Decimal values and return the result as a copy.
   * @param lhs left hand side Decimal value.
   * @param rhs right hand side Decimal value.
   * @return result of multiplication of the two decimal values.
   */
  LIBMPDECPP_EXPORT Decimal operator*( const Decimal &lhs, const Decimal &rhs );
  
  /** Add two Decimal values.
   * Add the given two Decimal values and return the result as a copy.
   * @param lhs left hand side Decimal value.
   * @param rhs right hand side Decimal value.
   * @return sum of the two decimal values.
   */
  LIBMPDECPP_EXPORT Decimal operator+( const Decimal &lhs, const Decimal &rhs );
  
  /** Subtract two Decimal values.
   * Subtract the given two Decimal values and return the result as a copy.
   * @param lhs left hand side Decimal value.
   * @param rhs right hand side Decimal value.
   * @return subtraction of the two decimal values.
   */
  LIBMPDECPP_EXPORT Decimal operator-( const Decimal &lhs, const Decimal &rhs );
  
  /** Divide two Decimal values.
   * Divide the given two Decimal values and return the result as a copy.
   * @param lhs left hand side Decimal value.
   * @param rhs right hand side Decimal value.
   * @return result of division.
   */
  LIBMPDECPP_EXPORT Decimal operator/( const Decimal &lhs, const Decimal &rhs );
  
  /** Remainder of integer division.
   * Determine the reminder of the division of the two given decimal values.
   * @param lhs left hand side Decimal value.
   * @param rhs right hand side Decimal value.
   * @return remainder of division.
   */
  LIBMPDECPP_EXPORT Decimal remainder( const Decimal &lhs, const Decimal &rhs );
  
  /** Remainder near of integer division.
   * Returns a - b * n, where n is the integer nearest the exact value of a / b. 
   * If two integers are equally near then the even one is chosen.
   * @param lhs left hand side Decimal value.
   * @param rhs right hand side Decimal value.
   * @return remainder near of division.
   */
  LIBMPDECPP_EXPORT Decimal remainderNear( const Decimal &lhs, const Decimal &rhs );
}

#endif // H_E3F615B483B54E9488FC4CE6F08D791E
