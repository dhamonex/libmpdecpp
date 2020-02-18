
#include <decimal.h>
#include <decimalexceptions.h>
#include <gtest/gtest.h>
#include <gmock/gmock.h>

#include <boost/exception/diagnostic_information.hpp>

#include "decimalinitenvironment.h"

using namespace ::testing;

TEST( Decimal, default_construction_test )
{
  mpdecimal::Decimal decimal;
  ASSERT_THAT( decimal.toString(), Eq( "0" ) );
}

int main( int argc, char **argv )
{
  InitGoogleTest( &argc, argv );
  AddGlobalTestEnvironment( new DecimalInitEnvironment );
  return RUN_ALL_TESTS();
}
