#ifndef H_A4E0DF4A6E1B4359BF34062CF3A10509
#define H_A4E0DF4A6E1B4359BF34062CF3A10509

#include <decimal.h>
#include <gtest/gtest.h>

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

#endif // H_A4E0DF4A6E1B4359BF34062CF3A10509
