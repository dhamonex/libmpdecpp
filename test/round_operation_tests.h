#ifndef H_CBD564007E454E7995A0EAB679584C6E
#define H_CBD564007E454E7995A0EAB679584C6E

class RoundOperationTest : public Test
{
public:
  RoundOperationTest() = default;
  ~RoundOperationTest() override = default;

protected:
  void SetUp() override
  {
    a = "5.5";
    b = "5.4";
  }

  mpdecpp::Decimal a;
  mpdecpp::Decimal b;
};

TEST_F( RoundOperationTest, round_up_test )
{
  ASSERT_THAT( mpdecpp::round( a ), Eq( 6 ) );
}

TEST_F( RoundOperationTest, round_down_test )
{
  ASSERT_THAT( mpdecpp::round( b ), Eq( 5 ) );
}

TEST_F( RoundOperationTest, round_truncate_test )
{
  ASSERT_THAT( mpdecpp::round( a, 0, mpdecpp::RoundMode::RoundTrunc ), Eq( 5 ) );
}

#endif // H_CBD564007E454E7995A0EAB679584C6E
