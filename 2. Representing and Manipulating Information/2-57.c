/* 
2.57 Write procedures show_short, show_long, and show_double that print the byte representations of C objects of
types short, long and double, respectively. Try these out on several machines.
*/

#include <stdio.h>

typedef unsigned char *byte_pointer;

void show_bytes(byte_pointer start, size_t len) {
    int i;
    for (i = 0; i < len; i++)
        printf(" %.2x", start[i]);
    printf("\n");
}

void show_short(int x) {
    show_bytes((byte_pointer) &x, sizeof(short));
}

void show_long(long x) {
    show_bytes((byte_pointer) &x, sizeof(long));
}

void show_double(double x) {
    show_bytes((byte_pointer) &x, sizeof(double));
}

void test_show(short x) {
    short short_value = x;
    long long_value = (long) x;
    double double_value = (double) x;

    show_short(short_value);
    show_long(long_value);
    show_double(double_value);
}

int main(void) {
    test_show(3070);
    return 0;
}

/* 
Output:
 fe 0b
 fe 0b 00 00
 00 00 00 00 00 fc a7 40

Output should be the same on all little-endian machines. We can see that long is 2 bytes longer than short and if we
flip it and convert it from hex to decimal, we get our input (3070).
Flipping and converting last output line from hex to double we get our input (3070.0).
*/  