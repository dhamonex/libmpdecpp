#include "decimal.h"
#include "mpdecimalnamespace.h"

MPDECIMAL_NAMESPACE_BEGIN

namespace detail
{
  struct DecimalPrivate
  {
  };
}

Decimal::Decimal()
  : m_private( new detail::DecimalPrivate )
{
}

Decimal::~Decimal()
{
}


MPDECIMAL_NAMESPACE_END
