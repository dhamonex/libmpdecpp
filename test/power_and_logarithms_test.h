#ifndef H_0C13CC5443174DC3A851D9738E7F2E87
#define H_0C13CC5443174DC3A851D9738E7F2E87

class PowerAndLogarithmTest : public Test
{
public:
  PowerAndLogarithmTest() = default;
  ~PowerAndLogarithmTest() override = default;

protected:
  void SetUp() override
  {
    a = 2;
    b = 5;
  }

  mpdecpp::Decimal a;
  mpdecpp::Decimal b;
  mpdecpp::Decimal c;
};

TEST_F( PowerAndLogarithmTest, exp_operation_test )
{
  ASSERT_THAT( mpdecpp::exp( b ).toString( 8 ), Eq( "148.41315910" ) );
}

TEST_F( PowerAndLogarithmTest, logarithm_calculation_test )
{
  ASSERT_THAT( mpdecpp::ln( b ).toString( 8 ), Eq( "1.60943791" ) );
}

TEST_F( PowerAndLogarithmTest, log10_calculation_test )
{
  ASSERT_THAT( mpdecpp::log( b ).toString( 8 ), Eq( "0.69897000" ) );
}

TEST_F( PowerAndLogarithmTest, power_calculation_test )
{
  ASSERT_THAT( mpdecpp::pow( a, b ), Eq( 32 ) );
}

TEST_F( PowerAndLogarithmTest, square_root_calculation_test )
{
  ASSERT_THAT( mpdecpp::sqrt( b ).toString( 8 ), Eq( "2.23606798" ) );
}

#endif // H_0C13CC5443174DC3A851D9738E7F2E87
