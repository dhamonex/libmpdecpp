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

MPDECIMAL_NAMESPACE_END
