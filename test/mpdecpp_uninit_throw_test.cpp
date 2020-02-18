#include <decimal.h>
#include <decimalexceptions.h>
#include <gtest/gtest.h>
#include <gmock/gmock.h>

using namespace ::testing;

TEST( DecimalPreConditions, check_throw_when_not_initialized )
{
  ASSERT_THROW( mpdecimal::Decimal(), mpdecimal::NotInitialized );
}

int main( int argc, char **argv )
{
  InitGoogleTest( &argc, argv );
  return RUN_ALL_TESTS();
}
