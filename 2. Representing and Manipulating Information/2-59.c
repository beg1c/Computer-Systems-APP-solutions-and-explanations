/* 
2.59 Write a C expression that will yield a word consisting of the least significant byte of 
x and the remaining bytes of y. For operands x = 0x89ABCDEF and y = 0x76543210, this would
give 0x765432EF.
*/

#include <stdio.h>

int replace_lsb(int x, int y) {
    int mask = 0xff;
    return (x & mask) | (y & ~mask);
}

int main(void) {
    printf("0x%08x\n", replace_lsb(0x89abcdef, 0x76543210));
    return 0;
}

/* 
Performing bitwise AND on 0x89abcdef (X) and 0x000000ff results in 0x000000ef. 
Similiarly performing bitwise AND on 0x76543210 and 0xffffff00 (obtained by computing NOT on 0xff)
results in 0x76543200. Lastly bitwise OR is computed on 0x000000ef and 0x76543200.
*/