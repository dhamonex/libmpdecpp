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
    }
    
    mpdecimal::Decimal twoDigitDecimalValue;
    mpdecimal::Decimal threeDigitDecimalValue;
    mpdecimal::Decimal fourDigitDecimalValue;
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
    }
    
    mpdecimal::Decimal decimalValue;
};

TEST_F( IntegerConversionTest, test_int32_conversion )
{
  ASSERT_THAT( decimalValue.toInt32(), Eq( 5 ) );
}

#endif // H_A7044423D0E2461989AA77A609704686

