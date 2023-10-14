/* 
2.58 Write a procedure is_little_endian that will return 1 when compiled and run on a little-endian machine,
and will return 0 when compiled and run on a big-endian machine. This program should run on any machine, regardless of
its word size. 
*/

#include <stdio.h>

int is_little_endian(void) {
    int set_lsb = 1;

    char *c = (char*) &set_lsb;

    return *c;
}

int main(void) {
    is_little_endian();
}

/* 
We assign an integer with value 1, setting the least significant byte to 1. 
Then we create a char pointer which points to the first byte at address of set_lsb.
Return will result either with value 1 for little-endian machines or 0 for big-endian machines.
*/