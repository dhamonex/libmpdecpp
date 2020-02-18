
#include <gtest/gtest.h>
#include <decimal.h>

class DecimalInitEnvironment : public ::testing::Environment
{
  public:
    DecimalInitEnvironment() = default;
    ~DecimalInitEnvironment() override = default;
    
    void SetUp() override
    {
      mpdecimal::Decimal::decimalInit( 128 );
    }
};

