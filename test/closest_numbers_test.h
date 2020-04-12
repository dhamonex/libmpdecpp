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

#endif // H_959949D873E64B3C9E891EA786A8AC14