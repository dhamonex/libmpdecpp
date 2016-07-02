#define BOOST_TEST_MODULE libdecimal_init_test
#include <boost/test/included/unit_test.hpp>

#include <decimal.h>

BOOST_AUTO_TEST_CASE( default_init_test )
{
  mpdecimal::Decimal decimal;
}

