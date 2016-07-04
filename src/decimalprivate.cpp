#include "decimalprivate.h"
#include "decimalexceptions.h"

#include <boost/throw_exception.hpp>

MPDECIMAL_NAMESPACE_BEGIN

namespace detail
{
  mpd_ssize_t DecimalPrivate::precision = 0;
  mpd_context_t DecimalPrivate::defaultContext;
  
  DecimalPrivate::DecimalPrivate()
    : context(), mpdDecimal()
  {
    if ( precision == 0 ) {
      BOOST_THROW_EXCEPTION( NotInitialized() 
        << ErrorString( "Decimal not initialized. Use Decimal::decimalInit to set precition and initialize decimal library" ) );
    }
    
    mpd_defaultcontext( &context );
    if ( !mpd_qsetprec( &context, precision ) ) {
      BOOST_THROW_EXCEPTION( DecimalException() << ErrorString( "Could not set precision" ) );
    }
    
    mpdDecimal.reset( mpd_new( &context ) );
    if ( context.status != 0 ) {
      BOOST_THROW_EXCEPTION( DecimalException() << ErrorString( "Could not create new decimal" ) << ErrorCode( context.status ) );
    }
    
    mpd_set_uint( mpdDecimal.get(), 0, &context );
    if ( context.status != 0 ) {
      BOOST_THROW_EXCEPTION( DecimalException() << ErrorString( "Could not initalize decimal" ) << ErrorCode( context.status ) );
    }
  }
}

MPDECIMAL_NAMESPACE_END
