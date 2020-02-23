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

Decimal::Decimal ( const Decimal& other )
  : m_private( std::make_unique<detail::DecimalPrivate>( *other.m_private ) )
{
  
}

Decimal::Decimal( Decimal &&other )
  : m_private( std::move( other.m_private ) )
{
  other = Decimal();
}

Decimal::~Decimal()
{
}

Decimal::Decimal( const std::string &value )
  : m_private( new detail::DecimalPrivate )
{
  m_private->setDecNumberValue( value );
}

Decimal::Decimal( int32_t value )
  : m_private( new detail::DecimalPrivate )
{
  m_private->setDecNumberValue( value );
}

Decimal::Decimal( int64_t value )
  : m_private( new detail::DecimalPrivate )
{
  m_private->setDecNumberValue( value );
}

Decimal::Decimal( uint32_t value )
  : m_private( new detail::DecimalPrivate )
{
  m_private->setDecNumberValue( value );
}

Decimal::Decimal( uint64_t value )
  : m_private( new detail::DecimalPrivate )
{
  m_private->setDecNumberValue( value );
}

Decimal &Decimal::operator=( const Decimal& other )
{
  m_private = std::make_unique<detail::DecimalPrivate>( *other.m_private );
  return *this;
}

Decimal &Decimal::operator=( Decimal &&other )
{
  m_private = std::move( other.m_private );
  other.m_private = std::make_unique<detail::DecimalPrivate>();
  return *this;
}

std::string Decimal::toString(unsigned int precision) const
{
  return m_private->toString( precision );
}

std::string Decimal::toString() const
{
  return m_private->toString();
}

void Decimal::decimalInit( std::size_t precision, 
                           RoundMode defaultRoundMode )
{
  assert( detail::DecimalPrivate::precision == 0 );
  
  mpd_init( &detail::DecimalPrivate::defaultContext, precision );
  detail::DecimalPrivate::setContextRoundMode( &detail::DecimalPrivate::defaultContext, defaultRoundMode );
  detail::DecimalPrivate::precision = precision;
}

MPDECIMAL_NAMESPACE_END
