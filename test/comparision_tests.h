#ifndef H_E999A6B99C1048C9A29168D7795B395A
#define H_E999A6B99C1048C9A29168D7795B395A

class DecimalComparionTest : public Test
{
public:
  DecimalComparionTest() = default;
  ~DecimalComparionTest() override = default;

protected:
  mpdecpp::Decimal a;
  mpdecpp::Decimal b;
  mpdecpp::Decimal c;
};

// ============ Equality Tests ==================

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

// ============ Less Than or Equal Tests ==================

class DecimalLessThanOrEqualComparisonTest : public DecimalComparionTest
{
protected:
  void SetUp() override
  {
    a = 5;
    b = 4;
    c = 5;
  }
};

TEST_F( DecimalLessThanOrEqualComparisonTest, test_less_or_equal_than_other_value )
{
  ASSERT_TRUE( b <= a );
  ASSERT_TRUE( c <= a );
}

TEST_F( DecimalLessThanOrEqualComparisonTest, test_less_or_equal_than_other_string_value )
{
  ASSERT_TRUE( "4" <= a );
  ASSERT_TRUE( c.toString() <= a );
}

TEST_F( DecimalLessThanOrEqualComparisonTest, test_less_or_equal_than_other_string_value_symmetric )
{
  ASSERT_TRUE( b <= "5" );
  ASSERT_TRUE( c <= a.toString() );
}

TEST_F( DecimalLessThanOrEqualComparisonTest, test_less_or_equal_than_other_int_value )
{
  ASSERT_TRUE( 4 <= a );
  ASSERT_TRUE( 5ul <= a );
}

TEST_F( DecimalLessThanOrEqualComparisonTest, test_less_or_equal_than_other_int_value_symmetric )
{
  ASSERT_TRUE( b <= 5 );
  ASSERT_TRUE( c <= 5ul );
}

// ============ Greater Than Tests ==================

class DecimalGreaterThanComparisonTest : public DecimalComparionTest
{
protected:
  void SetUp() override
  {
    a = 4;
    b = 5;
  }
};

TEST_F( DecimalGreaterThanComparisonTest, test_greater_than_other_value )
{
  ASSERT_TRUE( b > a );
}

TEST_F( DecimalGreaterThanComparisonTest, test_greater_than_other_string_value )
{
  ASSERT_TRUE( b.toString() > a );
}

TEST_F( DecimalGreaterThanComparisonTest, test_greater_than_other_string_value_symmetric )
{
  ASSERT_TRUE( b > "4" );
}

TEST_F( DecimalGreaterThanComparisonTest, test_greater_than_other_int_value )
{
  ASSERT_TRUE( 5 > a );
}

TEST_F( DecimalGreaterThanComparisonTest, test_greater_than_other_int_value_symmetric )
{
  ASSERT_TRUE( b > 4ul );
}

// ============ Greater Than or Equal Tests ==================

class DecimalGreaterThanOrEqualComparisonTest : public DecimalComparionTest
{
protected:
  void SetUp() override
  {
    a = 4;
    b = 5;
    c = 4;
  }
};

TEST_F( DecimalGreaterThanOrEqualComparisonTest, test_greater_than_or_equal_value )
{
  ASSERT_TRUE( b >= a );
  ASSERT_TRUE( c >= a );
}

TEST_F( DecimalGreaterThanOrEqualComparisonTest, test_greater_than_or_equal_string_value )
{
  ASSERT_TRUE( b.toString() >= a );
  ASSERT_TRUE( "5" >= a );
}

TEST_F( DecimalGreaterThanOrEqualComparisonTest, test_greater_than_or_equal_string_value_symmetric )
{
  ASSERT_TRUE( b >= "4" );
  ASSERT_TRUE( c >= "4" );
}

TEST_F( DecimalGreaterThanOrEqualComparisonTest, test_greater_than_or_equal_int_value )
{
  ASSERT_TRUE( 4 >= a );
  ASSERT_TRUE( 5ul >= a );
}

TEST_F( DecimalGreaterThanOrEqualComparisonTest, test_greater_than_or_equal_int_value_symmetric )
{
  ASSERT_TRUE( b >= 4 );
  ASSERT_TRUE( c >= 4ul );
}

// ============ Un-Equality Tests ==================

class DecimalUnEqualComparionTest : public DecimalComparionTest
{
protected:
  void SetUp() override
  {
    a = 5;
    b = 4;
    c = 5;
  }
};

TEST_F( DecimalUnEqualComparionTest, test_unequal_value )
{
  ASSERT_TRUE( a != b );
}

TEST_F( DecimalUnEqualComparionTest, test_false_on_equal_value )
{
  ASSERT_FALSE( a != c );
}

TEST_F( DecimalUnEqualComparionTest, test_unequal_string_value )
{
  ASSERT_TRUE( a != b.toString() );
}

// ============DecimalMinMaxTest ==============
class DecimalMinMaxTest : public DecimalComparionTest
{
protected:
  void SetUp() override
  {
    a = 5;
    b = 4;
  }
};

TEST_F( DecimalMinMaxTest, max_operator_test )
{
  ASSERT_THAT( mpdecpp::max( a, b ), Eq( 5 ) );
}

TEST_F( DecimalMinMaxTest, min_operator_test )
{
  ASSERT_THAT( mpdecpp::min( a, b ), Eq( 4 ) );
}

#endif // H_E999A6B99C1048C9A29168D7795B395A
