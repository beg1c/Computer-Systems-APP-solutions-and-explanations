/* 
2.56 Try running the code for show_bytes for different sample values.
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
    int* pointer_value = &int_value;

    show_int(int_value);
    show_float(float_value);
    show_pointer(pointer_value);
}

int main(void) {
    test_show_bytes(3070);
    printf("\n");
    test_show_bytes(13532);
    printf("\n");
    test_show_bytes(53250);
    return 0;
}

/* 
Output:
 fe 0b 00 00
 00 e0 3f 45
 b0 f9 df 31 3a 00 00 00

 dc 34 00 00
 00 70 53 46
 b0 f9 df 31 3a 00 00 00

 02 d0 00 00
 00 02 50 47
 b0 f9 df 31 3a 00 00 00

Output is similiar to problem 2.55, although we can notice that pointer address stays the same for every function call. 
*/  