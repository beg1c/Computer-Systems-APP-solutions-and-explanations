/* 
2.73 Write code for a function with the following prototype:

    Addition that saturates to TMin or TMax
    int saturating_add(int x, int y);

Instead of overflowing the way normal two's-complement addition does, saturating addition returns TMax when there would be positive overflow,
and TMin when there would be negative overflow. Saturating arithmetic is commonly used in programs that perform digital signal processing.

Your function should follow the bit-level integer coding rules (page 164).
*/
#include <stdio.h>
#include <limits.h>

int saturating_add(int x, int y) {
    int sum = x + y;
    int signature_mask = INT_MIN;

    int negative_overflow = (signature_mask & x) && (signature_mask & y) && !(signature_mask & sum);
    int positive_overflow = !(signature_mask & x) && !(signature_mask & y) && (signature_mask & sum);

    (negative_overflow && (sum = INT_MIN) || positive_overflow && (sum = INT_MAX));

    return sum;
}

int main(void) {
    saturating_add(3213, 32112);
    return 0;
}

/* 
We can first detect positive or negative overflow with following logic:
If x < 0 and y < 0 but sum >= 0, we have a negative overflow. 
If x > 0 and y > 0 but sum < 0, we have positive overflow. 

We can create a signature mask to test for positive or negative numbers. We use INT_MIN as it will set the most significant bit to 1 and 
everything else to zero. If we perform &AND on our mask and any X, we will get positive result if X is negative and zero as result if X is positive. 

We can then write test for negative overflow like: (signature_mask & x) && (signature_mask & y) && !(signature_mask & sum).
And for positive overflow: !(signature_mask & x) && !(signature_mask & y) && (signature_mask & sum).

We then check if there is negative or positive overflow and set sum to INT_MIN or INT_MAX accordingly. 
*/