#ifndef H_A46CBFFE0C9A455B9F3CF36E23A75889
#define H_A46CBFFE0C9A455B9F3CF36E23A75889

class DivideTest : public Test
{
public:
  DivideTest() = default;
  ~DivideTest() override = default;

protected:
  void SetUp() override
  {
    a = 10;
    b = 5;
    c = 2;
  }

  mpdecimal::Decimal a;
  mpdecimal::Decimal b;
  mpdecimal::Decimal c;
};

TEST_F( DivideTest, divide_assign_test )
{
  a /= b;
  ASSERT_THAT( a.toInt64(), Eq( 2 ) );
}

TEST_F( DivideTest, divide_and_return_copy_test )
{
  auto result = a / b;
  ASSERT_THAT( a.toInt64(), Eq( 10 ) );
  ASSERT_THAT( b.toInt64(), Eq( 5 ) );
  ASSERT_THAT( result.toInt64(), Eq( 2 ) );
}

TEST_F( DivideTest, divide_three_values_test )
{
  auto result = a / b / c;
  ASSERT_THAT( result.toInt64(), Eq( 1 ) );
}

TEST_F( DivideTest, modulo_operator_test )
{
  b %= c;
  ASSERT_THAT( b.toInt64(), Eq( 1 ) );
}

TEST_F( DivideTest, modulo_operator_copy_test )
{
  auto res = b % c;
  ASSERT_THAT( res.toInt64(), Eq( 1 ) );
}

TEST_F( DivideTest, remainder_near_operation_test )
{
  ASSERT_THAT( remainderNear( b, c ), Eq( 1 ) );
}

#endif // H_A46CBFFE0C9A455B9F3CF36E23A75889
