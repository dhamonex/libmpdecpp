#ifndef H_C883E6DC0F574EBF938CFC13C70F203B
#define H_C883E6DC0F574EBF938CFC13C70F203B

class SummationTest : public Test
{
public:
  SummationTest() = default;
  ~SummationTest() override = default;

protected:
  void SetUp() override
  {
    a = 5;
    b = 8;
    c = 1;
  }

  mpdecimal::Decimal a;
  mpdecimal::Decimal b;
  mpdecimal::Decimal c;
};

TEST_F( SummationTest, addition_assignment_test )
{
  a += c;
  ASSERT_THAT( a.toInt64(), Eq( 6 ) );
}

TEST_F( SummationTest, add_and_return_copy_test )
{
  auto result = a + b;
  ASSERT_THAT( result.toInt64(), Eq( 13 ) );
}

TEST_F( SummationTest, sum_up_three_values_test )
{
  auto result = a + b + c;
  ASSERT_THAT( result.toInt64(), Eq( 14 ) );
}

TEST_F( SummationTest, pre_increment_operator_test )
{
  ASSERT_THAT( ++a, Eq( 6 ) );
  ASSERT_THAT( a, Eq( 6 ) );
}

TEST_F( SummationTest, post_increment_operator_test )
{
  ASSERT_THAT( a++, Eq( 5 ) );
  ASSERT_THAT( a, Eq( 6 ) );
}

#endif // H_C883E6DC0F574EBF938CFC13C70F203B
