#include "operations.h"
#include "decimal.h"
#include "decimalprivate.h"

#include "mpdecimalnamespace.h"

#include <iostream>

MPDECIMAL_NAMESPACE_BEGIN

bool operator==( const Decimal& lhs, const Decimal& rhs )
{
  return detail::ComparisonResult::Equal == lhs.m_private->compareToOtherValue( *rhs.m_private );
}

bool operator<( const Decimal &lhs, const Decimal &rhs )
{
  return detail::ComparisonResult::Less == lhs.m_private->compareToOtherValue( *rhs.m_private );
}

bool operator<=( const Decimal &lhs, const Decimal &rhs )
{
  return lhs == rhs || lhs < rhs;
}

bool operator>( const Decimal &lhs, const Decimal &rhs )
{
  return detail::ComparisonResult::Greater == lhs.m_private->compareToOtherValue( *rhs.m_private );
}

bool operator>=( const Decimal &lhs, const Decimal &rhs )
{
  return lhs == rhs || lhs > rhs;
}

bool operator!=( const mpdecimal::Decimal& lhs, const mpdecimal::Decimal& rhs )
{
  return !( lhs == rhs );
}

Decimal operator* ( const mpdecimal::Decimal& lhs, const mpdecimal::Decimal& rhs )
{
  Decimal result{ lhs };
  result *= rhs;
  
  return result;
}

mpdecimal::Decimal operator+ ( const mpdecimal::Decimal &lhs, const mpdecimal::Decimal &rhs )
{
  Decimal result{ lhs };
  result += rhs;
  
  return result;
}

MPDECIMAL_NAMESPACE_END

