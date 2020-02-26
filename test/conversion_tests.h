#ifndef H_A7044423D0E2461989AA77A609704686
#define H_A7044423D0E2461989AA77A609704686

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

TEST_F( StringConversionTest, test_string_conversion_with_round_down_with_reset )
{
  ASSERT_THAT( twoDigitDecimalValue.toString( 0, mpdecimal::RoundMode::RoundDown ), Eq( "5" ) );
  ASSERT_THAT( twoDigitDecimalValue.toString( 0 ), Eq( "6" ) );
}

#endif // H_A7044423D0E2461989AA77A609704686

