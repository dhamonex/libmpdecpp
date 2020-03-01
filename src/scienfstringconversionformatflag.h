#ifndef H_32C31210F2E14865B3531E494EF8273B
#define H_32C31210F2E14865B3531E494EF8273B

namespace mpdecimal
{
  /** Formatflag for converting Decimal to string in sci or eng formatting.
   * Specify the format of the exponent character.
   */
  enum class SciEngStringConversionFormatFlag
  {
    UpperCaseExponentCharacter, ///< The exponent character is upper case.
    LowerCaseExponentCharacter  ///< The exponent character is lower case.
  };
}

#endif // H_32C31210F2E14865B3531E494EF8273B
