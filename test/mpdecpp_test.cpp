
#include <decimal.h>
#include <decimalexceptions.h>
#include <gtest/gtest.h>
#include <gmock/gmock.h>

#include <boost/exception/diagnostic_information.hpp>

using namespace ::testing;

// BOOST_AUTO_TEST_CASE( default_init_test )
// {
//   mpdecimal::Decimal::decimalInit( 128 );
//   
//   mpdecimal::Decimal decimal;
//   
//   BOOST_CHECK( "0" == decimal.toString() );
// }

TEST( DecimalPreConditions, check_throw_when_not_initialized )
{
  ASSERT_THROW( mpdecimal::Decimal(), mpdecimal::NotInitialized );
}

int main( int argc, char **argv )
{
  InitGoogleTest( &argc, argv );
  return RUN_ALL_TESTS();
}
