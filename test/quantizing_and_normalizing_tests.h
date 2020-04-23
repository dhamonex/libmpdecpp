#ifndef H_73C6C14112AE43599A286423E77CEE49
#define H_73C6C14112AE43599A286423E77CEE49

class QuanizeTestAndNormalizeTest : public Test
{
public:
  QuanizeTestAndNormalizeTest() = default;
  ~QuanizeTestAndNormalizeTest() override = default;

protected:
  void SetUp() override
  {
    value = "5.5555";
  }

  mpdecimal::Decimal value;
};

TEST_F( QuanizeTestAndNormalizeTest, quanize_value_test )
{
  ASSERT_THAT( mpdecimal::quantize( value, 6 ).toString( 4 ), Eq( "5.5555" ) );
}

#endif // H_73C6C14112AE43599A286423E77CEE49
