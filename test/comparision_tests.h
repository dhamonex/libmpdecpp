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

// ============ Equality Tests ==================

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

// ============ Less Than Tests ==================

class DecimalLessThanComparisonTest : public DecimalComparionTest
{
  protected:
    void SetUp() override
    {
      a = 5;
      b = 4;
    }
};

TEST_F( DecimalLessThanComparisonTest, test_less_than_other_decimal )
{
  ASSERT_TRUE( b < a );
}

TEST_F( DecimalLessThanComparisonTest, test_less_than_other_string )
{
  ASSERT_TRUE( "4" < a );
}

TEST_F( DecimalLessThanComparisonTest, test_less_than_other_string_symmetric )
{
  ASSERT_TRUE( b < a.toString() );
}

TEST_F( DecimalLessThanComparisonTest, test_less_than_other_int )
{
  ASSERT_TRUE( 4 < a );
}

TEST_F( DecimalLessThanComparisonTest, test_less_than_other_int_symmetric )
{
  ASSERT_TRUE( b < 5ul );
}

#endif // H_E999A6B99C1048C9A29168D7795B395A
