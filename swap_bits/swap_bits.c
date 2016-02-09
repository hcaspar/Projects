unsigned char	swap_bits(unsigned char octet)
{
	octet = (octet << 4) + (octet >> 4);
	return (octet);
}
