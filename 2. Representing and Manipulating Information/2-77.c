/* 
2.77 Suppose we are given the task of generating code to multiply integer variable x by various different constant factors K.
To be efficient, we want to use only the operations +, - and <<. For the following values of K, write C expressions
to perform the multipliication using at most three operations per expression.
*/
#include <stdio.h>

int A(int x) {
    return (x << 4) + x;
}

int B(int x) {
    return x - (x << 3);
}

int C(int x) {
    return (x << 6) - (x << 2);
}

int D(int x) {
    return (x << 4) - (x << 7);
}

int main(void) {
    A(10);
    B(10);
    C(20);
    D(20);
    return 0;
}

/* 
A. Shifting left by 4 is equal to multiplying by 16, we then just have to add one X to get the same result as we woul by multiplying with 17. 
B. We can shift X left three places to get 8X and then subtract that from X to get -7X.
C. X<<6 equals to 64X and we subtract X<2 which is 4X from it to get 60X.
D. We subtract 128X (X<<7) from 16X (X<<4) to get -112X.
*/