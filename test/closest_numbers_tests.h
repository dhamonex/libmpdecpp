#ifndef H_959949D873E64B3C9E891EA786A8AC14
#define H_959949D873E64B3C9E891EA786A8AC14

class ClosesNumberTest : public Test
{
  public:
    ClosesNumberTest() = default;
    ~ClosesNumberTest() override = default;
    
  protected:
    void SetUp() override
    {
      testValue = 5;
    }
    
    mpdecimal::Decimal testValue;
};

TEST_F( ClosesNumberTest, next_minus_test )
{
  ASSERT_THAT( mpdecimal::nextMinus( testValue ).toString( 27, mpdecimal::RoundMode::RoundTrunc ), Eq( "4.999999999999999999999999999" ) );
}

TEST_F( ClosesNumberTest, next_plus_test )
{
  ASSERT_THAT( mpdecimal::nextPlus( testValue ).toString( 27, mpdecimal::RoundMode::RoundUp ), Eq( "5.000000000000000000000000001" ) );
}

class ClosesNumberNextTowardTest : public ClosesNumberTest
{
  protected:
    void SetUp() override
    {
      testValue = 5;
      towards = 4;
    }
    
    mpdecimal::Decimal towards;
};

TEST_F( ClosesNumberNextTowardTest, next_toward_test )
{
  ASSERT_THAT( mpdecimal::nextToward( testValue, towards ).toString( 27, mpdecimal::RoundMode::RoundTrunc ), Eq( "4.999999999999999999999999999" ) );
}

#endif // H_959949D873E64B3C9E891EA786A8AC14
