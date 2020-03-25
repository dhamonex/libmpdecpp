#ifndef H_7C685D0A423944D3988E058C5158C259
#define H_7C685D0A423944D3988E058C5158C259

class SubtractionTest : public Test
{
  public:
    SubtractionTest() = default;
    ~SubtractionTest() override = default;
    
  protected:
    void SetUp() override
    {
      a = 10;
      b = 3;
      c = -2;
    }
    
    mpdecimal::Decimal a;
    mpdecimal::Decimal b;
    mpdecimal::Decimal c;
};

TEST_F( SubtractionTest, subtract_and_assign_test )
{
  a -= b;
  ASSERT_THAT( a.toInt64(), Eq( 7 ) );
}

TEST_F( SubtractionTest, subtract_and_return_copy_test )
{
  auto result = a - b;
  ASSERT_THAT( result.toInt64(), Eq( 7 ) );
}

TEST_F( SubtractionTest, sum_up_three_values_test )
{
  auto result = a - b - c;
  ASSERT_THAT( result.toInt64(), Eq( 9 ) );
}

TEST_F( SubtractionTest, pre_decrement_operator_test )
{
  ASSERT_THAT( --a, Eq( 9 ) );
  ASSERT_THAT( a, Eq( 9 ) );
}

TEST_F( SubtractionTest, post_decrement_operator_test )
{
  ASSERT_THAT( a--, Eq( 10 ) );
  ASSERT_THAT( a, Eq( 9 ) );
}

#endif // H_7C685D0A423944D3988E058C5158C259
