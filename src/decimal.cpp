#include "decimal.h"
#include "mpdecimalnamespace.h"
#include "decimaltypes.h"
#include "decimalexceptions.h"
#include "decimalprivate.h"

#include <boost/throw_exception.hpp>
#include <boost/lexical_cast.hpp>

MPDECIMAL_NAMESPACE_BEGIN

Decimal::Decimal()
  : m_private( new detail::DecimalPrivate )
{
}

Decimal::~Decimal()
{
}

std::string Decimal::toString(unsigned int precision) const
{
  m_private->resetStatus();
  const std::string formatString( "." + boost::lexical_cast<std::string>( precision ) + "f" );
  detail::MPDecimalCharPointer formatedResult( mpd_format( m_private->mpdDecimal.get(), formatString.c_str(), &m_private->context ) );
  
  if ( m_private->context.status != 0 ) {
    BOOST_THROW_EXCEPTION( DecimalException() << ErrorString( "Format error (" + formatString + ")" ) << ErrorCode( m_private->context.status ) );
  }
  
  return formatedResult.get();
}

std::string Decimal::toString() const
{
  m_private->resetStatus();
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
