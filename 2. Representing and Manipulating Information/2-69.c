/* 
2.69 Write code for a function with the following prototype:

Do rotating left shift. Assume 0 <= n < w
Examples when x = 0x12345678 and w = 32:
    n=4 -> 0x23456781, n=20 -> 0x67812345

unsigned rotate_left(unsigned x, int n);

Your function should follow the bit-level integer coding rules (page 164). Be careful of the case n = 0.
*/

int rotate_left(unsigned x, int n) {
    int shift_left = x << n;
    int shift_right = x >> (31-n) >> 1;

    return shift_left | shift_right;
}


int main(void) {
    rotate_left(0x12345678, 20);
    return 0;
}

/* 
In first line of a function we are shifting x left by n places to fill those places with zeroes. In second line we are
shifting x right 31-n + 1 places so we can compute |OR in our return value to get our desired result. 

For x = 0x12345678 and n = 20 shift_left is: 0x67800000 and shift_right is: 0x00012345. 

If we use ^XOR instead of |OR, we would get 0 as result in case of n = 0 because shift_right would be resolved to 0. It is
important we use (31 - n) + 1, instead of 32-n, while shifting so we don't cause undefined behavior if n is 0 (shifting by more than w-1).
*/