/* 
2.70 Write code for the function with the following prototype:

Return 1 when x can be represented as an n-bit, 2's-complement number; 0 otherwise
Assume 1 <= n <= w

int fits_bits(int x, int n);

Your function should follow the bit-level integer coding rules (page 164).
*/

int fits_bits(int x, int n) {
    int word_size = sizeof(int) << 3;
    int shift = x << (word_size - n) >> (word_size - n);

    return shift == x;
}


int main(void) {
    fits_bits(-9, 4);
    return 0;
}

/* 
Let's say we have decimal number -30 and that we use 16-bit binary system. Converting that number to two's complement binary we get 1111 1111 1110 0010.
If you understand two's complement good enough, you should know that we can remove all but last one from left side in this binary number and still get the 
same decimal number. If we removed the last one, we would change the sign and get positive number. So we can remove 10 bits (and be left with 6) from left side without 
changing the number, that means we can represent -30 as atleast 6-bit two's complement binary.

Let's see if we can represent it as 5-bit two's complement. We shift that number left by 16 (wordsize) - 5 = 11 places and right again. That way we will
"delete" first 11 digits. If we look at binary number above, we can notice that after shifting left by 11 places, we will end with 0 as sign bit: 0001 0000 0000 0000.
Shifting right again won't result in same number so we can conclude -30 can't be represented as 5-bit two's complement.

If we wanted to test if it could be represented by 8-bit for example, we would have:
1110 0010 0000 0000 - after left shift, sign bit is 1, arithmetic shift will fill with ones
1111 1111 1110 0010 - same number
*/