#ifndef H_C7620FF9BCE14CD98F7E9AF0FF652DAE
#define H_C7620FF9BCE14CD98F7E9AF0FF652DAE

namespace mpdecimal
{
  /** The rounding modes taken from mpdecimal.
   * Details look at https://www.bytereef.org/mpdecimal/doc/libmpdec/context.html#rounding
   */
  enum class RoundMode
  {
    RoundUp,          ///< round away from 0.
    RoundDown,        ///< round toward 0 (truncate).
    RoundCeiling,     ///< round toward +infinity.
    RoundFloor,       ///< round toward -infinity.
    RoundHalfUp,      ///< 0.5 is rounded up.
    RoundHalfDown,    ///< 0.5 is rounded down.
    RoundHalfEven,    ///< 0.5 is rounded to even.
    Round05Up,        ///< round zero or five away from 0.
    RoundTrunc,       ///< truncate, but set infinities.
    Default           ///< Default rounding mode (on initialization this is RoundHalfEven).
  };
}

#endif // H_C7620FF9BCE14CD98F7E9AF0FF652DAE
