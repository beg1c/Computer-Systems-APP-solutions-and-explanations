/* 
2.60 Suppose we number the bytes in a w-bit word from 0 (least significant) to w/8 - 1 (most significant).
Write code for the following C function, which will return an unsigned value in which byte i of argument x
has been replaced by byte b:

unsigned replace_byte (unsigned x, int i, unsigned char b);

Here are some examples showing how the function should work: 

replace_byte(0x12345678, 2, 0xAB) --> 0x12AB5678
replace_byte(0x12345678, 0, 0xAB) --> 0x123456AB
*/

#include <stdio.h>

unsigned replace_byte(unsigned x, int i, unsigned char b) {
    unsigned masked_x = x & ~(0xff << (i*8));
    return masked_x | (b << i*8);
}

int main(void) {
    printf("0x%08x\n", replace_byte(0x12345678, 0, 0xab));
    return 0;
}

/* 
First we set desired byte in X to 0 by shifting 0xff left by i*8(bit) places. For first example that results in
0x00ff0000, we can then compute ~NOT and get 0xff00ffff. Using bitwise &AND on X and this mask, we get 0x12005678.
Now we can use same left shift by i*8 places to get mask 0x000000ab --> 0x00ab0000. Performing |OR on this mask and
masked_x gives us our result.
*/