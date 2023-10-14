/* 
2.61 Write C expressions that evaluate to 1 when the following conditions are true and to 0 when tey are false.
Assume X is of type int.

A. Any bit of x equals 1.
B. Any bit of x equals 0.
C. Any bit in the least significant byte of x equals 1.
D. Any bit in the most significant byte of x equals 0.

Your code should follow the bit-level integer coding rules (page 164), with the additional restriction that
you may not use equality (==) or inequality (!=) tests.
*/

#include <stdio.h>

int evaluateA(int x) {
    int evaluateA = x & 0xffffffff;

    //Evaluate everything other than 0 to 1
    return !(!evaluateA);
}

int evaluateB(int x) {
    int evaluateB = ~x & 0xffffffff;

    return !(!evaluateB);
}

int evaluateC(int x) {
    int evaluateC = x & 0xff;

    return !(!evaluateC);
}

int evaluateD(int x) {
    int shift_value = (sizeof(int)-1) << 3;
    
    int evaluateD = (~x >> shift_value) & 0xff;

    return !(!evaluateD);
}

int main(void) {
    printf("%d\n", evaluateA(0x00100000)); //A.
    printf("%d\n", evaluateB(0xffff0fff)); //B.
    printf("%d\n", evaluateC(0x00000010)); //C.
    printf("%d\n", evaluateD(0x0500000)); //D.

    return 0;
}

/* 
A. We are comparing every bit of X with 1. If any bit of X is 1, it will evaluate to some integer other than 0. 
    We call logical !NOT two times while returning because it will evaluate every number other than 0 to 1.
B. We are basically repeating evaluateA with using bitwise ~NOT on X. It will treat zeroes as ones and vice-versa 
    to evaluate.
C. We can again use logic from evaluateA, but we will only use the least significant byte as mask. (0x000000ff)
D. This is a little bit different because we first need to find the size of our integer word and subtract one byte
    so we can apply right shifts which will move most significant byte at the place of least significant byte. 
    Further work is combination of evaluateB and evaluateC. We perform bitwise ~NOT and perform &AND with 0xff.
*/