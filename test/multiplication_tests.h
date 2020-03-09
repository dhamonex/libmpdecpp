#ifndef H_CB603DE2F3D24B2D8929ED8A7F332398
#define H_CB603DE2F3D24B2D8929ED8A7F332398

class MultiplicationTest : public Test
{
  public:
    MultiplicationTest() = default;
    ~MultiplicationTest() = default;
    
  protected:
    void SetUp() override
    {
      a = 5;
      b = 6;
      c = -1;
    }
    
    mpdecimal::Decimal a;
    mpdecimal::Decimal b;
    mpdecimal::Decimal c;
};

TEST_F( MultiplicationTest, multiplication_assignment_test )
{
  a *= b;
  ASSERT_THAT( a.toInt64(), Eq( 30 ) );
}

TEST_F( MultiplicationTest, multiply_and_copy_test )
{
  auto result = a * b;
  ASSERT_THAT( result.toInt64(), Eq( 30 ) );
  ASSERT_THAT( a, Eq( 5 ) );
  ASSERT_THAT( b, Eq( 6 ) );
}

#endif // H_CB603DE2F3D24B2D8929ED8A7F332398
