#define BOOST_TEST_MODULE libdecimal_init_test
#include <boost/test/included/unit_test.hpp>

#include <decimal.h>
#include <decimalexceptions.h>

#include <boost/exception/diagnostic_information.hpp>

BOOST_AUTO_TEST_CASE( uninit_exception_test )
{
  BOOST_CHECK_THROW( mpdecimal::Decimal(), mpdecimal::NotInitialized );
}

BOOST_AUTO_TEST_CASE( default_init_test )
{
  mpdecimal::Decimal::decimalInit( 128 );
  
  mpdecimal::Decimal decimal;
  
  BOOST_CHECK( "0" == decimal.toString() );
}

