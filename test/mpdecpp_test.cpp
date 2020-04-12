
#include <decimal.h>
#include <decimalexceptions.h>
#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include <utility>

#include <boost/exception/diagnostic_information.hpp>

#include "decimalinitenvironment.h"

namespace mpdecimal
{
  std::ostream &operator<<( std::ostream &s, const Decimal &value )
  {
    s << value.toString( RoundMode::Default );
    return s;
  }
}

using namespace ::testing;

#include "initialization_tests.h"
#include "conversion_tests.h"
#include "comparision_tests.h"
#include "multiplication_tests.h"
#include "summation_test.h"
#include "subtraction_tests.h"
#include "divide_tests.h"
#include "power_and_logarithms_test.h"
#include "sign_tests.h"
#include "round_operation_test.h"
#include "closest_numbers_test.h"

int main( int argc, char **argv )
{
  InitGoogleTest( &argc, argv );
  AddGlobalTestEnvironment( new DecimalInitEnvironment );
  return RUN_ALL_TESTS();
}
