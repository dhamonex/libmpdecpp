
#include <decimal.h>
#include <decimalexceptions.h>
#include <gmock/gmock.h>
#include <gtest/gtest.h>
#include <utility>

#include <boost/exception/diagnostic_information.hpp>

#include "decimalinitenvironment.h"

namespace mpdecpp
{
  std::ostream &operator<<( std::ostream &s, const Decimal &value )
  {
    s << value.toString( RoundMode::Default );
    return s;
  }
} // namespace mpdecpp

using namespace ::testing;

#include "closest_numbers_tests.h"
#include "comparision_tests.h"
#include "conversion_tests.h"
#include "divide_tests.h"
#include "initialization_tests.h"
#include "integral_operation_tests.h"
#include "multiplication_tests.h"
#include "power_and_logarithms_test.h"
#include "quantizing_and_normalizing_tests.h"
#include "round_operation_tests.h"
#include "sign_tests.h"
#include "subtraction_tests.h"
#include "summation_test.h"

int main( int argc, char **argv )
{
  InitGoogleTest( &argc, argv );
  AddGlobalTestEnvironment( new DecimalInitEnvironment );
  return RUN_ALL_TESTS();
}
