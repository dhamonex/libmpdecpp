#ifndef H_F9358506B15F44BBB06B42EDB1A94810
#define H_F9358506B15F44BBB06B42EDB1A94810

TEST( DecimalInitialization, initialize_on_construction )
{
  mpdecpp::Decimal dec;
  ASSERT_THAT( dec.toString(), Eq( "0" ) );
}

TEST( DecimalInitialization, initialize_from_int_32 )
{
  int32_t value{ 10 };
  mpdecpp::Decimal dec{ value };
  ASSERT_THAT( dec.toString(), Eq( "10" ) );
}

TEST( DecimalInitialization, initialize_from_int_64 )
{
  int64_t value{ 9223372036854775807l };
  mpdecpp::Decimal dec{ value };
  ASSERT_THAT( dec.toString(), Eq( "9223372036854775807" ) );
}

TEST( DecimalInitialization, initialize_from_uint_32 )
{
  uint32_t value{ 10 };
  mpdecpp::Decimal dec{ value };
  ASSERT_THAT( dec.toString(), Eq( "10" ) );
}

TEST( DecimalInitialization, initialize_from_uint_64 )
{
  uint64_t value{ 18446744073709551615ul };
  mpdecpp::Decimal dec{ value };
  ASSERT_THAT( dec.toString(), Eq( "18446744073709551615" ) );
}

TEST( DecimalInitialization, initialize_from_string )
{
  mpdecpp::Decimal dec{ "18446744073709551615" };
  ASSERT_THAT( dec.toString(), Eq( "18446744073709551615" ) );
}

TEST( DecimalInitialization, copy_initialize )
{
  mpdecpp::Decimal dec{ 10 };
  mpdecpp::Decimal other{ dec };

  ASSERT_THAT( other.toString(), Eq( "10" ) );
  ASSERT_THAT( dec.toString(), Eq( "10" ) );
}

TEST( DecimalInitialization, move_initialize )
{
  mpdecpp::Decimal dec{ 10 };
  mpdecpp::Decimal other{ std::move( dec ) };

  ASSERT_THAT( other.toString(), Eq( "10" ) );
  ASSERT_THAT( dec.toString(), Eq( "0" ) );
}

TEST( DecimalInitialization, copy_assign_initialize )
{
  mpdecpp::Decimal dec{ 10 };
  mpdecpp::Decimal other = dec;

  ASSERT_THAT( other.toString(), Eq( "10" ) );
  ASSERT_THAT( dec.toString(), Eq( "10" ) );
}

TEST( DecimalInitialization, move_assign_initialize )
{
  mpdecpp::Decimal dec{ 10 };
  mpdecpp::Decimal other = std::move( dec );

  ASSERT_THAT( other.toString(), Eq( "10" ) );
  ASSERT_THAT( dec.toString(), Eq( "0" ) );
}

#endif // H_F9358506B15F44BBB06B42EDB1A94810
