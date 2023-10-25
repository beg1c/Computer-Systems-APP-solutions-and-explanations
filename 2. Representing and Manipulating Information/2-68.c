/* 
2.68 Write a code for a function with the following prototype: 

Mask with the least significant n bits set to 1
Examples: n = 6 --> 0x3F, n = 17 --> 0x1FFFF
Assume 1 <= n <= w

int lower_one_mask(int n);

Your function should follow the bit-level integer coding rules (page 164). Be careful of case n = w.
*/

int lower_one_mask(int n) {
    int mask = ~(-1 << (n-1) << 1);

    return mask;
}


int main(void) {
    lower_one_mask(17);
    return 0;
}

/* 
We can shift -1 (all ones in two's complement) by n places left to fill with 0 bits. Then we can compute
~NOT on our result to change zeroes to ones and vice versa. We need to be careful at case n = w. Shifting 
behaviour is undefined in such case so we are firstly shifting by n - 1 and then by 1 more to be sure that we get
the right result.
*/