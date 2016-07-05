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
  return m_private->toString( precision );
}

std::string Decimal::toString() const
{
  return m_private->toString();
}

void Decimal::decimalInit( std::size_t precision )
{
  assert( detail::DecimalPrivate::precision == 0 );
  
  mpd_init( &detail::DecimalPrivate::defaultContext, precision );
  detail::DecimalPrivate::precision = precision;
}


MPDECIMAL_NAMESPACE_END
