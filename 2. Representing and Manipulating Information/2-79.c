/* 
2.79 Write code for a function mul3div4 that, for integer argument x, computes 3 * x/4 but follows the bit-level integer
coding rules (page 164). Your code should replicate the fact that computation 3*x can cause overflow.
*/
#include <stdio.h>
#include <limits.h>

int divide_power2(int x, int k) {
    int is_negative = x & INT_MIN;
    (is_negative && (x = x + (1 << k) - 1));
    return x >> k;
}

int mul3div4(int x) {
    int multiply = (x << 1) + x;
    int result = divide_power2(multiply, 2);
    return result;
}

int main(void) {
    printf("%d", mul3div4(-100));
    return 0;
}

/* 
We can use function divide_power2 from last task for division. In mul3div4 function we shift X left by 1 place which is equal
to multiplying by two and we add X to get 3X. We then pass our multiplication result to divide_power2 with k=2 as we want
to divide with 4. 
*/