/* 
2.78 Write code for a function with the following prototype:
    Divide by power of 2. Assume 0 <= k < w-1 
    int divide_power2(int x, int k);

The function should compute x/2k with correct rounding, and it should follow the bit-level integer coding rules (page 164).
*/
#include <stdio.h>
#include <limits.h>

int divide_power2(int x, int k) {
    int is_negative = x & INT_MIN;
    (is_negative && (x = x + (1 << k) - 1));
    return x >> k;
}

int main(void) {
    printf("%d", divide_power2(-12340, 4));
    return 0;
}

/* 
We can achieve division by power of 2 with shifting right by arbitrary ammount of places. If we, for example, want to divide by 16,
we would shift number right 4 places. 
In order to get correct rounding with negative numbers, we have to apply bias to second line of our function. I won't explain bias 
here as there is better explanation with examples at pages 141 and 142 of this book. Briefly, bias increments bits that won't be
shifted out to round up the result.
*/