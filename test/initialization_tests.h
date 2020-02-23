
TEST( DecimalInitialization, initialize_on_construction )
{
  mpdecimal::Decimal dec;
  ASSERT_THAT( dec.toString(), Eq( "0" ) );
}
