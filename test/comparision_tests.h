#ifndef H_E999A6B99C1048C9A29168D7795B395A
#define H_E999A6B99C1048C9A29168D7795B395A

class DecimalComparionTest : public Test
{
  public:
    DecimalComparionTest() = default;
    ~DecimalComparionTest() override = default;
    
  protected:
    mpdecimal::Decimal a;
    mpdecimal::Decimal b;
};

class DecimalEqualComparionTest : public DecimalComparionTest
{
  protected:
    void SetUp() override
    {
      a = 5;
      b = 5;
    }
};

TEST_F( DecimalEqualComparionTest, test_on_equality )
{
  ASSERT_TRUE( a == b );
}

TEST_F( DecimalEqualComparionTest, test_against_string_on_equality )
{
  ASSERT_TRUE( "5" == a );
}

TEST_F( DecimalEqualComparionTest, test_against_string_on_equality_symmetry )
{
  ASSERT_TRUE( a == "5" );
}

TEST_F( DecimalEqualComparionTest, test_int_on_equality )
{
  ASSERT_TRUE( 5 == b );
}

TEST_F( DecimalEqualComparionTest, test_int_on_equality_symmetry )
{
  ASSERT_TRUE( b == 5 );
}

TEST_F( DecimalEqualComparionTest, test_unsigned_int_on_equality )
{
  ASSERT_TRUE( 5ul == b );
}

TEST_F( DecimalEqualComparionTest, test_unsigned_int_on_equality_symmetry )
{
  ASSERT_TRUE( b == 5ul );
}

#endif // H_E999A6B99C1048C9A29168D7795B395A
