#ifndef H_A7044423D0E2461989AA77A609704686
#define H_A7044423D0E2461989AA77A609704686

// ============== String Conversion ===================
class StringConversionTest : public Test
{
  public:
    StringConversionTest() = default;
    ~StringConversionTest() override = default;
    
  protected:
    void SetUp() override
    {
      twoDigitDecimalValue = "5.55";
      threeDigitDecimalValue = "-5.005";
      fourDigitDecimalValue = "10.0005";
      exponentRepresentationValue = "123E+1";
    }
    
    mpdecimal::Decimal twoDigitDecimalValue;
    mpdecimal::Decimal threeDigitDecimalValue;
    mpdecimal::Decimal fourDigitDecimalValue;
    mpdecimal::Decimal exponentRepresentationValue;
};

TEST_F( StringConversionTest, test_conversion_with_round_down_with_reset )
{
  ASSERT_THAT( twoDigitDecimalValue.toString( 0, mpdecimal::RoundMode::RoundDown ), Eq( "5" ) );
  ASSERT_THAT( twoDigitDecimalValue.toString( 0 ), Eq( "6" ) );
}

TEST_F( StringConversionTest, test_string_conversion_round_half_even )
{
  ASSERT_THAT( twoDigitDecimalValue.toString( 1 ), Eq( "5.6" ) );
  ASSERT_THAT( threeDigitDecimalValue.toString( 2 ), Eq( "-5.00" ) );
  ASSERT_THAT( fourDigitDecimalValue.toString( 2 ), Eq( "10.00" ) );
}

TEST_F( StringConversionTest, test_string_conversion_round_half_down )
{
  ASSERT_THAT( twoDigitDecimalValue.toString( 1, mpdecimal::RoundMode::RoundDown ), Eq( "5.5" ) );
  ASSERT_THAT( threeDigitDecimalValue.toString( 2, mpdecimal::RoundMode::RoundDown ), Eq( "-5.00" ) );
  ASSERT_THAT( fourDigitDecimalValue.toString( 2, mpdecimal::RoundMode::RoundDown ), Eq( "10.00" ) );
}

TEST_F( StringConversionTest, test_string_conversion_round_trunc )
{
  ASSERT_THAT( twoDigitDecimalValue.toString( 1, mpdecimal::RoundMode::RoundTrunc ), Eq( "5.5" ) );
  ASSERT_THAT( threeDigitDecimalValue.toString( 2, mpdecimal::RoundMode::RoundTrunc ), Eq( "-5.00" ) );
  ASSERT_THAT( fourDigitDecimalValue.toString( 2, mpdecimal::RoundMode::RoundTrunc ), Eq( "10.00" ) );
}

TEST_F( StringConversionTest, test_eng_string_conversion_lower_case_exponent )
{
  ASSERT_THAT( exponentRepresentationValue.toEngString( mpdecimal::SciEngStringConversionFormatFlag::LowerCaseExponentCharacter ), Eq( "1.23e+3" ) );
}

TEST_F( StringConversionTest, test_eng_string_conversion_upper_case_exponent )
{
  ASSERT_THAT( exponentRepresentationValue.toEngString( mpdecimal::SciEngStringConversionFormatFlag::UpperCaseExponentCharacter ), Eq( "1.23E+3" ) );
}

TEST_F( StringConversionTest, test_sci_string_conversion_lower_case_exponent )
{
  ASSERT_THAT( exponentRepresentationValue.toSciString( mpdecimal::SciEngStringConversionFormatFlag::LowerCaseExponentCharacter ), Eq( "1.23e+3" ) );
}

TEST_F( StringConversionTest, test_sci_string_conversion_upper_case_exponent )
{
  ASSERT_THAT( exponentRepresentationValue.toSciString( mpdecimal::SciEngStringConversionFormatFlag::UpperCaseExponentCharacter ), Eq( "1.23E+3" ) );
}

// ============== Integer Conversion ===================
class IntegerConversionTest : public Test
{
  public:
    IntegerConversionTest() = default;
    ~IntegerConversionTest() override = default;
    
  protected:
    void SetUp() override
    {
      decimalValue = "5";
      notConvertable = "5.5";
      negativeValue = "-5";
    }
    
    mpdecimal::Decimal decimalValue;
    mpdecimal::Decimal notConvertable;
    mpdecimal::Decimal negativeValue;
};

TEST_F( IntegerConversionTest, test_int32_conversion )
{
  ASSERT_THAT( decimalValue.toInt32(), Eq( 5 ) );
  ASSERT_THAT( negativeValue.toInt32(), Eq( -5 ) );
  static_assert( std::is_same_v< decltype( std::declval<mpdecimal::Decimal>().toInt32() ), int32_t> );
}

TEST_F( IntegerConversionTest, test_int64_conversion )
{
  ASSERT_THAT( decimalValue.toInt64(), Eq( 5 ) );
  ASSERT_THAT( negativeValue.toInt64(), Eq( -5 ) );
  static_assert( std::is_same_v< decltype( std::declval<mpdecimal::Decimal>().toInt64() ), int64_t> );
}

TEST_F( IntegerConversionTest, test_exception_when_not_convertable )
{
  ASSERT_THROW( notConvertable.toInt32(), mpdecimal::DecimalException );
}

TEST_F( IntegerConversionTest, test_uint32_conversion)
{
  auto convertedVal = decimalValue.toUInt32();
  ASSERT_THAT( convertedVal, Eq( 5 ) );
  static_assert(std::is_same_v< decltype( convertedVal ), uint32_t> );
}

#endif // H_A7044423D0E2461989AA77A609704686

