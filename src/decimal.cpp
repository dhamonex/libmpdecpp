#include "decimal.h"
#include "mpdecimalnamespace.h"
#include "decimaltypes.h"
#include "decimalexceptions.h"

#include <boost/throw_exception.hpp>
#include <boost/lexical_cast.hpp>

MPDECIMAL_NAMESPACE_BEGIN

namespace detail
{
  struct LIBMPDECIMAL_NO_EXPORT DecimalPrivate
  {
    DecimalPrivate()
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
    
    mpd_context_t context;
    MPDDecimalPointer mpdDecimal;
    
    
    static mpd_ssize_t precision;
    static mpd_context_t defaultContext;
  };
  
  mpd_ssize_t DecimalPrivate::precision = 0;
  mpd_context_t DecimalPrivate::defaultContext;
}

Decimal::Decimal()
  : m_private( new detail::DecimalPrivate )
{
}

Decimal::~Decimal()
{
}

std::string Decimal::toString(unsigned int precision) const
{
  const std::string formatString( "." + boost::lexical_cast<std::string>( precision ) + "f" );
  detail::MPDecimalCharPointer formatedResult( mpd_format( m_private->mpdDecimal.get(), formatString.c_str(), &m_private->context ) );
  
  if ( m_private->context.status != 0 ) {
    BOOST_THROW_EXCEPTION( DecimalException() << ErrorString( "Format error (" + formatString + ")" ) << ErrorCode( m_private->context.status ) );
  }
  
  return formatedResult.get();
}

std::string Decimal::toString() const
{
  detail::MPDecimalCharPointer formatedResult( mpd_to_eng( m_private->mpdDecimal.get(), 0 ) );
  
  if ( m_private->context.status != 0 ) {
    BOOST_THROW_EXCEPTION( DecimalException() << ErrorString( "String conversion error" ) << ErrorCode( m_private->context.status ) );
  }
  
  return formatedResult.get();
}

void Decimal::decimalInit( std::size_t precision )
{
  assert( detail::DecimalPrivate::precision == 0 );
  
  mpd_init( &detail::DecimalPrivate::defaultContext, precision );
  detail::DecimalPrivate::precision = precision;
}


MPDECIMAL_NAMESPACE_END
