#ifndef H_BB62A1910CDB4DD3BB886D3DB0227C3F
#define H_BB62A1910CDB4DD3BB886D3DB0227C3F

class SignTest : public Test
{
public:
  SignTest() = default;
  ~SignTest() override = default;

protected:
  void SetUp() override
  {
    negativeValue = -5;
    positiveValue = 5;
  }

  mpdecpp::Decimal negativeValue;
  mpdecpp::Decimal positiveValue;
};

TEST_F( SignTest, abs_test_with_negative_value )
{
  ASSERT_THAT( mpdecpp::abs( negativeValue ), Eq( 5 ) );
}

TEST_F( SignTest, abs_test_with_positive_value )
{
  ASSERT_THAT( mpdecpp::abs( positiveValue ), Eq( 5 ) );
}

TEST_F( SignTest, flip_sign_positive_value_test )
{
  auto value = -positiveValue;
  ASSERT_THAT( value, Eq( -5 ) );
}

TEST_F( SignTest, flip_sign_negative_value_test )
{
  auto value = -negativeValue;
  ASSERT_THAT( value, Eq( 5 ) );
}

TEST_F( SignTest, plus_on_negative_value_test )
{
  auto value = +negativeValue;
  ASSERT_THAT( value, Eq( negativeValue ) );
}

TEST_F( SignTest, plus_on_positive_value_test )
{
  auto value = +positiveValue;
  ASSERT_THAT( value, Eq( positiveValue ) );
}

#endif // H_BB62A1910CDB4DD3BB886D3DB0227C3F
