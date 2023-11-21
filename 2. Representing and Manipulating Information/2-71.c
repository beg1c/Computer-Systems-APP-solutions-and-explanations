/* 
2.71 You just started working for a company that is implementing a set of procedures to operate on a data structure where 4 signed bytes are packed 
into a 32-bit unsigned. Bytes within the word are numbered from 0 (least significant) to 3 (most significant). You have been assigned the task of 
implementing a function for a machine using two's-complement arithmetic and arithmetic right shifts with the following prototype:

    Declaration of data type where 4 bytes are packed into an unsigned
    typedef unsigned packed_t;

    Extract byte from word. Return as signed integer. 
    int xbyte(packed_t word, int bytenum);

That is, the function will extract the designated byte and sign extend it to be a 32-bit int. Your predecessor (who was fire for incompetence) wrote 
the following code:

    int xbyte(packed_t word, int bytenum)
    {
        return (word >> (bytenum << 3)) & 0xFF;
    }

A. What is wrong with this code?
B. Give a correct implementation of the function that uses only left and right shifts along with one subtraction.
*/

typedef unsigned packed_t;

int xbyte(packed_t word, int bytenum) {
    return (word << ((3 - bytenum) << 3)) >> 24;
}


/* 
A. This code shifts word left by bytenum * 8 places (left shifting by 3 is equal to multiplying by 8) and computes &AND with mask 0xFF.
If we think of a 32-bit word: 10101010 01101100 10011111 10011111 and we pick bytenum = 2, we should extract 01101100.
Let's check if that is true for this code. It would shift word right (arithmetic) by bytenum*8 places, so 16 places. 11111111 11111111 10101010 01101100. 
If we performed last step, &AND with 0xFF, we would get 00000000 00000000 00000000 01101100. Which is correct for this scenario, 
but what if we wanted to use bytenum = 3? We would get 00000000 00000000 00000000 10101010 which is not correct because our 
integer is not correctly sign extended. 

B. We can shift left by (3 - bytenum)*8 places to move byte to most significant byte and then we can shift right by 24 places to move it to 
least significant byte and sign get our result. For our example with bytenum = 1, it would look like:

10101010 01101100 10011111 10011111 / compute 3-bytenum and multiply it by eight, we get 16, shift integer left by 16 places
10011111 10011111 00000000 00000000 / now shift it right by 24 places (arithmetic)
11111111 11111111 11111111 10011111 / we get our correct result
*/