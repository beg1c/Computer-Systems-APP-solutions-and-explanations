/* 
2.62 Write a function int_shifts_arithmetic() that yields 1 when run on a machine that uses arithmetic right 
shifts for data type int and yields 0 otherwise. Your code should work on a machine with any wordsize. Test your
code on several machines.
*/


int int_shifts_arithmetic() {
    int shift_value = (sizeof(int)<<3) - 1; //int size in bits - 1
    int shifted = (-1 >> shift_value);
    return -1 == shifted;
}

int main(void) {
    int_shifts_arithmetic();
    return 0;
}

/* 
There are many aproaches to this problem. Number -1 is represented as all ones in two's complement binary, for example
(1 1 1 1) if we use only 4 bits. If we shift it right by shift_value, we get either 0001 (1 in decimal) or 1111 (-1 in decimal).
We then compare shifted with -1, if shifted is equal to -1 we have a machine that uses arithmetic shift and otherwise.
*/