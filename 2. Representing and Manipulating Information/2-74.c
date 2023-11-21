/* 
2.74 Write a function with the following prototype:

Determine whether arguments can be subtracted without overflow
int tsub_ok(int x, int y);

This function should return 1 if the computation x-y does not overflow. 
*/

#include <stdio.h>

int tsub_ok(int x, int y) {
    int sub = x - y;

    int overflow = x > 0 && y < 0 && sub < 0 || x < 0 && y > 0 && sub > 0;

    return !overflow;
}

int main(void) {
    tsub_ok(-321132, -2031132131);
    return 0;
}

/* 
We can determine if subtraction operation overflows with following tests:
Positive overflow x > 0 && y < 0 && sub < 0
Negative overflow x < 0 && y > 0 && sub > 0

We then perform !NOT on overflow in our return call to return 1 if overflow was 0 and to return 0 if overflow happened.
*/