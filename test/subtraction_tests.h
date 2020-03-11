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

#endif // H_7C685D0A423944D3988E058C5158C259
