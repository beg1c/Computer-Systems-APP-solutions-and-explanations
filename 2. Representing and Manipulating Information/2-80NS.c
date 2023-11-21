/* 
2.80 Write code for a function threefourths that, for integer argument x, computes the value of 3/4*X, rounded toward zero.
It should not overflow. Your function should follow the bit-level integer coding rules (page 164).
*/

#include <stdio.h>
#include <limits.h>

int divide_power2(int x, int k) {
    int is_negative = x & INT_MIN;
    (is_negative && (x = x + (1 << k) - 1));
    return x >> k;
}

int threefourths(int x) {
    int multiply = (x << 1) + x;
    int result = divide_power2(multiply, 2);
    return result;
}

int main(void) {
    printf("%d", threefourths(-11111));
    return 0;
}

/* 
This task is similiar to 2.79 but the result of this task should not overflow so we are faced with a problem. 
We can divide first and then multiply in which case we get wrong result because of rounding. If we first multiply and 
then divide, we get the right result but we are risking overflow.

I did not solve this task yet. I will try to solve it in the future.
*/