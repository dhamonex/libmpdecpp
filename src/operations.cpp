#include "operations.h"
#include "decimal.h"
#include "decimalprivate.h"

#include "mpdecimalnamespace.h"

#include <iostream>

MPDECIMAL_NAMESPACE_BEGIN

bool operator==( const Decimal &lhs, const Decimal &rhs )
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

Decimal max( const Decimal &lhs, const Decimal &rhs )
{
  if ( lhs > rhs ) {
    return lhs;
  }

  return rhs;
}

Decimal min( const Decimal &lhs, const Decimal &rhs )
{
  if ( lhs < rhs ) {
    return lhs;
  }

  return rhs;
}

bool operator!=( const Decimal &lhs, const Decimal &rhs )
{
  return !( lhs == rhs );
}

Decimal operator*( const Decimal &lhs, const Decimal &rhs )
{
  Decimal result{ lhs };
  result *= rhs;

  return result;
}

Decimal operator+( const Decimal &lhs, const Decimal &rhs )
{
  Decimal result{ lhs };
  result += rhs;

  return result;
}

Decimal operator+( const Decimal &value )
{
  Decimal result{ value };
  result.m_private->plusAssign();

  return result;
}

Decimal operator-( const Decimal &lhs, const Decimal &rhs )
{
  Decimal result{ lhs };
  result -= rhs;

  return result;
}

Decimal operator-( const Decimal &value )
{
  Decimal result{ value };
  result.m_private->minusAssign();

  return result;
}

Decimal operator/( const Decimal &lhs, const Decimal &rhs )
{
  Decimal result{ lhs };
  result /= rhs;

  return result;
}

Decimal operator%( const Decimal &lhs, const Decimal &rhs )
{
  Decimal result{ lhs };
  result %= rhs;

  return result;
}

Decimal remainderNear( const Decimal &lhs, const Decimal &rhs )
{
  Decimal result{ lhs };
  result.m_private->remainderNearAssign( *rhs.m_private );

  return result;
}

Decimal exp( const Decimal &value )
{
  Decimal result{ value };
  result.m_private->expAndAssign();

  return result;
}

Decimal ln( const Decimal &value )
{
  Decimal result{ value };
  result.m_private->lnAndAssign();

  return result;
}

Decimal log( const Decimal &value )
{
  Decimal result{ value };
  result.m_private->log10AndAssign();

  return result;
}

Decimal pow( const Decimal &base, const Decimal &exp )
{
  Decimal result{ base };
  result.m_private->powAndAssign( *exp.m_private );

  return result;
}

Decimal sqrt( const Decimal &value )
{
  Decimal result{ value };
  result.m_private->sqrtAndAssign();

  return result;
}

Decimal abs( const Decimal &value )
{
  Decimal result{ value };
  result.m_private->abs();

  return result;
}

Decimal nextMinus( const Decimal &value )
{
  Decimal result{ value };
  result.m_private->nextMinusAssign();

  return result;
}

Decimal nextPlus( const Decimal &value )
{
  Decimal result{ value };
  result.m_private->nextPlusAssing();

  return result;
}

Decimal nextToward( const Decimal &value, const Decimal &towards )
{
  Decimal result{ value };
  result.m_private->nextTowardAssign( *towards.m_private );

  return result;
}

Decimal round( const Decimal &value, unsigned int precision, RoundMode roundMode )
{
  return value.toString( precision, roundMode );
}

Decimal quantize( const Decimal &value, const Decimal &exp )
{
  Decimal result{ value };
  result.m_private->quantizeAssign( *exp.m_private );

  return value;
}

Decimal floor( const Decimal &value )
{
  Decimal result{ value };
  result.m_private->floorAssign();

  return result;
}

Decimal ceil( const Decimal &value )
{
  Decimal result{ value };
  result.m_private->ceilAssign();

  return result;
}

MPDECIMAL_NAMESPACE_END
