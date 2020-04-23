#ifndef H_CA33FD5823B041D19EA1D732CE29F098
#define H_CA33FD5823B041D19EA1D732CE29F098

class IntegralOperationTest : public Test
{
public:
  IntegralOperationTest() = default;
  ~IntegralOperationTest() override = default;

protected:
  void SetUp() override
  {
    value = "5.5";
  }

  mpdecimal::Decimal value;
};

TEST_F( IntegralOperationTest, floor_operation_test )
{
  ASSERT_THAT( mpdecimal::floor( value ), Eq( 5 ) );
}

TEST_F( IntegralOperationTest, ceil_operation_test )
{
  ASSERT_THAT( mpdecimal::ceil( value ), Eq( 6 ) );
}

#endif // H_CA33FD5823B041D19EA1D732CE29F098
