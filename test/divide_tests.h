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

#endif // H_A46CBFFE0C9A455B9F3CF36E23A75889
