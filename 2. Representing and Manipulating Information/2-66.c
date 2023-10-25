/* 
2.66 Write code to implement the following function:

Generate mask indicating leftmost 1 in x. Assume w = 32.
For example, 0xFF00 -> 0x8000, and 0x6600 -> 0x4000.
If x = 0, then return 0.

int leftmost_one(unsigned x);

Your function should follow the bit-level integer coding rules (page 164), except that you may assume that data type int
has w = 32 bits. Your code should contain a total of at most 15 arithmetic, bitwise, and logical operations. Hint: First
transform x into a bit vector of the form [0 ... 011 ... 1].
*/

int leftmost_one(unsigned x) {
    x = x | (x >> 16); //1st step
    x = x | (x >> 8); //2nd step
    x = x | (x >> 4); //3rd step
    x = x | (x >> 2); //4th step
    x = x | (x >> 1); //5th step
    x = x ^ (x >> 1); //6th step
    return x;
}


int main(void) {
    leftmost_one(0x0BCDEF78);
    return 0;
}

/* 
If we follow hint from the book, our goal is to convert every bit on the right side of leftmost one to 1. Then we can shift that value right by one place and compute
^XOR with non-shifted value which will set all bits, except the leftmost one, to zero. We can set all right bits to one by shifting x with by 16, 8, 4, 2, 1 and performing
|OR with non-shifted x. I've again printed the output in binary to understand it easier:

Our x in binary:
0000 1011 1100 1101 1110 1111 0111 1000
1st step:
0000 1011 1100 1101 1110 1111 1111 1101
2nd step:
0000 1011 1100 1111 1110 1111 1111 1111
3rd step:
0000 1011 1111 1111 1111 1111 1111 1111
4th step:
0000 1011 1111 1111 1111 1111 1111 1111
5th step:
0000 1111 1111 1111 1111 1111 1111 1111
6th step:
0000 1000 0000 0000 0000 0000 0000 0000 

In last step we just shift value from 5th step one place to the right and perform ^XOR, which leaves only our leftmost bit as one.
*/