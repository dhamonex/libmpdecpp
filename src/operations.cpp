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

mpdecimal::Decimal max( const mpdecimal::Decimal &lhs, const mpdecimal::Decimal &rhs )
{
  if ( lhs > rhs ) {
    return lhs;
  }
  
  return rhs;
}

mpdecimal::Decimal min( const mpdecimal::Decimal &lhs, const mpdecimal::Decimal &rhs )
{
  if ( lhs < rhs ) {
    return lhs;
  }
  
  return rhs;
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

mpdecimal::Decimal operator+ ( const mpdecimal::Decimal& value )
{
  Decimal result{ value };
  result.m_private->plusAssign();
  
  return result;
}

mpdecimal::Decimal operator- ( const mpdecimal::Decimal &lhs, const mpdecimal::Decimal &rhs )
{
  Decimal result{ lhs };
  result -= rhs;
  
  return result;
}

mpdecimal::Decimal operator- ( const mpdecimal::Decimal& value )
{
  Decimal result{ value };
  result.m_private->minusAssign();
  
  return result;
}

mpdecimal::Decimal operator/ ( const mpdecimal::Decimal &lhs, const mpdecimal::Decimal &rhs )
{
  Decimal result{ lhs };
  result /= rhs;
  
  return result;
}

mpdecimal::Decimal operator% ( const mpdecimal::Decimal& lhs, const mpdecimal::Decimal& rhs )
{
  Decimal result{ lhs };
  result %= rhs;
  
  return result;
}

mpdecimal::Decimal remainderNear( const mpdecimal::Decimal& lhs, const mpdecimal::Decimal& rhs )
{
  Decimal result{ lhs };
  result.m_private->remainderNearAssign( *rhs.m_private );
  
  return result;
}

mpdecimal::Decimal exp( const mpdecimal::Decimal &value )
{
  Decimal result{ value };
  result.m_private->expAndAssign();
  
  return result;
}

mpdecimal::Decimal ln( const mpdecimal::Decimal& value )
{
  Decimal result{ value };
  result.m_private->lnAndAssign();
  
  return result;
}

mpdecimal::Decimal log( const mpdecimal::Decimal& value )
{
  Decimal result{ value };
  result.m_private->log10AndAssign();
  
  return result;
}

mpdecimal::Decimal pow( const mpdecimal::Decimal& base, const mpdecimal::Decimal& exp )
{
  Decimal result{ base };
  result.m_private->powAndAssign( *exp.m_private );
  
  return result;
}

mpdecimal::Decimal sqrt( const mpdecimal::Decimal& value )
{
  Decimal result{ value };
  result.m_private->sqrtAndAssign();
  
  return result;
}

mpdecimal::Decimal abs( const mpdecimal::Decimal& value )
{
  Decimal result{ value };
  result.m_private->abs();
  
  return result;
}

MPDECIMAL_NAMESPACE_END

