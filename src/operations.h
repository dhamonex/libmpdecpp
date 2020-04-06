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
  
  /** Max function.
  * Compares two Decimal values on and returns the maxium of both.
  * @param lhs left hand side Decimal value.
  * @param rhs right hand side Decimal value.
  * @return max Decimal value.
  */
  LIBMPDECPP_EXPORT Decimal max( const Decimal &lhs, const Decimal &rhs );
  
  /** Min function.
  * Compares two Decimal values on and returns the minimum of both.
  * @param lhs left hand side Decimal value.
  * @param rhs right hand side Decimal value.
  * @return min Decimal value.
  */
  LIBMPDECPP_EXPORT Decimal min( const Decimal &lhs, const Decimal &rhs );
  
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
  
  /** Apply plus sign on Decimal value.
   * Applies the plus sign.
   * @param value Decimal value
   * @return result of operation.
   */
  LIBMPDECPP_EXPORT Decimal operator+( const Decimal &value );
  
  /** Subtract two Decimal values.
   * Subtract the given two Decimal values and return the result as a copy.
   * @param lhs left hand side Decimal value.
   * @param rhs right hand side Decimal value.
   * @return subtraction of the two decimal values.
   */
  LIBMPDECPP_EXPORT Decimal operator-( const Decimal &lhs, const Decimal &rhs );
  
  /** Modify sign of a Decimal value.
   * Apply negative sign on decimal value.
   * @param value value where to apply sign.
   * @return result of operation.
   */
  LIBMPDECPP_EXPORT Decimal operator-( const Decimal &value );
  
  /** Divide two Decimal values.
   * Divide the given two Decimal values and return the result as a copy.
   * @param lhs left hand side Decimal value.
   * @param rhs right hand side Decimal value.
   * @return result of division.
   */
  LIBMPDECPP_EXPORT Decimal operator/( const Decimal &lhs, const Decimal &rhs );
  
  /** Modulo operator of two Decimal values.
   * Divide two Decimal values and return the modulo value as copy.
   * @param lhs left hand side Decimal value.
   * @param rhs right hand side Decimal value.
   * @return modulo value.
   */
  LIBMPDECPP_EXPORT Decimal operator%( const Decimal &lhs, const Decimal &rhs );
  
  /** Remainder near of integer division.
   * Returns a - b * n, where n is the integer nearest the exact value of a / b. 
   * If two integers are equally near then the even one is chosen.
   * @param lhs left hand side Decimal value.
   * @param rhs right hand side Decimal value.
   * @return remainder near of division.
   */
  LIBMPDECPP_EXPORT Decimal remainderNear( const Decimal &lhs, const Decimal &rhs );
  
  /** Exp operation.
   * Returns e ** v where v is a Decimal value. "Inexact Rounded" Errors are ignored by this function
   * and not throwing an exception.
   * @param value Decimal value for exp function.
   * @return e ** v.
   */
  LIBMPDECPP_EXPORT Decimal exp( const Decimal &value );
  
  /** Ln operation.
   * Returns ln from value value. "Inexact Rounded" Errors are ignored by this function
   * and not throwing an exception.
   * @param value Decimal value for ln calculation.
   * @return ln of value.
   */
  LIBMPDECPP_EXPORT Decimal ln( const Decimal &value );
  
  /** Log 10 operation.
   * Returns base-10 logarithm from value. "Inexact Rounded" Errors are ignored by this function
   * and not throwing an exception.
   * @param value Decimal value for log 10 calculation.
   * @return log 10 of value.
   */
  LIBMPDECPP_EXPORT Decimal log( const Decimal &value );
  
  /** Power operation.
   * Returns power of base ** exp.
   * @param base the base Decimal value.
   * @param exp the Decimal value exponent.
   * @return base ** exp
   */
  LIBMPDECPP_EXPORT Decimal pow( const Decimal &base, const Decimal &exp );
  
  /** Square root operation.
   * Calculates the square root of the given Decimal value. 
   * This function ignores "Inexact Rounded" Error and always uses the ROUND_HALF_EVEN mode.
   * @param value Decimal value.
   * @return square root of value.
   */
  LIBMPDECPP_EXPORT Decimal sqrt( const Decimal &value );
  
  /** Absolute operation.
   * Determine absolute value of given Decimal value.
   * @param value Decimal value.
   * @return absolute value.
   */
  LIBMPDECPP_EXPORT Decimal abs( const Decimal &value );
}

#endif // H_E3F615B483B54E9488FC4CE6F08D791E
