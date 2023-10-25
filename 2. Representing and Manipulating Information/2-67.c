/* 
2.67 You are given the task of writing a procedure in_size_is_32() that yields 1 when run on a machine for which an int is 
32-bits, and yields 0 otherwise. You are not allowed to use the sizeof operator. Here is a first attempt:

The following code does not run properly on some machines
int bad_int_size_is_32() {
    int set_msb = 1 << 31;
    int beyond_msb = 1 << 32;

    return set_msb && !beyond_msb;
}

When compiled and run on a 32-bit SUN SPARC, however, this procedure returns 0. The following compiler message gives us an
indication of the problem: warning: left shift count >= width of type

A. In what way does our code fail to comply with C standard?
B. Modify the code to run properly on any machine for which data type int is at least 32 bits.
C. Modify the code to run properly on any machine for which data type int is at least 16 bits.

Your code should follow the bit-level integer coding rules (page 164), with the additional restriction that you may not use
equality (==) or inequality (!=) tests.
*/

int int_size_is_32() {
    int set_msb = 1 << 15 << 15 << 1;
    int beyond_msb = set_msb << 1;

    return set_msb && !beyond_msb;
}


int main(void) {
    int_size_is_32();
    return 0;
}

/* 
A. The behaviour of shift operations where shift value is bigger than word size - 1 is undefined in C standard. On some machines it will
work, on other not. Considering that, it is best to avoid undefined behaviour and write code that will be portable over any machine.
B and C. We can shift by values lower than 16 to make sure our code will work on 16-bit machines. 
*/