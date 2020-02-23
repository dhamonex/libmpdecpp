
#include <decimal.h>
#include <decimalexceptions.h>
#include <gtest/gtest.h>
#include <gmock/gmock.h>

#include <boost/exception/diagnostic_information.hpp>

#include "decimalinitenvironment.h"

using namespace ::testing;

#include "initialization_tests.h"

int main( int argc, char **argv )
{
  InitGoogleTest( &argc, argv );
  AddGlobalTestEnvironment( new DecimalInitEnvironment );
  return RUN_ALL_TESTS();
}
