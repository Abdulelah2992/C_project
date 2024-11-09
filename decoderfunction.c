#include<stdio.h>
#include <stdbool.h>
//mem[i] =mem[i] | 1<<(7-j);

void decoder_function(char ch, bool* j, bool* c, bool* d1, bool* d0, bool* sreg, bool* s, bool* custom1, bool* custom0)
{
	*j   = (ch & 0x80) != 0; // 0x80: 10000000 - First (most significant) bit
	*c  = (ch & 0x40) != 0; // 0x40: 01000000 - Second bit
	*d1   = (ch & 0x20) != 0; // 0x20: 00100000 - Third bit
	*d0  = (ch & 0x10) != 0; // 0x10: 00010000 - Fourth bit
	*sreg   = (ch & 0x08) != 0; // 0x08: 00001000 - Fifth bit
	*s   = (ch & 0x04) != 0; // 0x04: 00000100 - Sixth bit
	*custom1 = (ch & 0x02) != 0; // 0x02: 00000010 - Seventh bit
	*custom0  = (ch & 0x01) != 0; // 0x01: 00000001 - Eighth (least significant) bit
}
