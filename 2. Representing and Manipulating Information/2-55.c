/* 
2.55 Compile and run the sample code that uses show_bytes (file show-bytes.c) on different machines to which you have access. 
Determine the byte orderings used by these machines.
*/

#include <stdio.h>

typedef unsigned char *byte_pointer;

void show_bytes(byte_pointer start, size_t len) {
    int i;
    for (i = 0; i < len; i++)
        printf(" %.2x", start[i]);
    printf("\n");
}

void show_int(int x) {
    show_bytes((byte_pointer) &x, sizeof(int));
}

void show_float(float x) {
    show_bytes((byte_pointer) &x, sizeof(float));
}

void show_pointer(void *x) {
    show_bytes((byte_pointer) &x, sizeof(void *));
}

void test_show_bytes(int x) {
    int int_value = x;
    float float_value = (float) x;
    int* pointer_value = &x;

    show_int(int_value);
    show_float(float_value);
    show_pointer(pointer_value);
}

int main(void) {
    test_show_bytes(3070);
    return 0;
}

/*
Output on my Desktop-PC running Windows 11: 
 fe 0b 00 00
 00 e0 3f 45
 10 fe 1f e5 c4 00 00 00

Output on Programiz C online compiler: 
 fe 0b 00 00
 00 e0 3f 45
 1c 4f 3f 4b fc 7f 00 00

Output is indicating that both machines are little endian. 
If we flip the first ouput line "fe 0b 00 00" and convert it from two-complement to decimal, we get our input (3070). 
Flipping second output line "00 e0 3f 45" and converting it from hex to IEEE-754 we recieve our input casted to float (3070.0).
Last output line shows the virtual address of input value and it will be different between any two machines. It also changes when we run the code second time.
Both machines are 64-bit which is indicated by pointer size (8 bytes).
*/