
#include <decimal.h>
#include <decimalexceptions.h>
#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include <utility>

#include <boost/exception/diagnostic_information.hpp>

#include "decimalinitenvironment.h"

using namespace ::testing;

#include "initialization_tests.h"
#include "conversion_tests.h"
#include "comparision_tests.h"
#include "multiplication_tests.h"
#include "summation_test.h"

int main( int argc, char **argv )
{
  InitGoogleTest( &argc, argv );
  AddGlobalTestEnvironment( new DecimalInitEnvironment );
  return RUN_ALL_TESTS();
}
