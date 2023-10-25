/* 
2.65 Write code to implement the following function:

Retuurn 1 when x contains and odd number of 1s; 0 otherwise.
    Assume w=32
int odd_ones(unsigned x);

Your function should follow the bit-level integer coding rules (page 164), except that you may assume that data type int
has w = 32 bits. 
Your code should containt a total of at most 12 arithmetic, bitwise, and logical operations.
*/

int odd_ones(unsigned x)
{   
    x = (x & 0x0000FFFF) ^ (x >> 16); //1st step
    x = (x & 0x000000FF) ^ (x >> 8); //2nd step
    x = (x & 0x0000000F) ^ (x >> 4); //3rd step
    x = (x & 0x00000003) ^ (x >> 2); //4th step
    x = (x & 0x00000001) ^ (x >> 1); //5th step
    return x;
}


int main(void) {
    odd_ones(0xABCDEF78);
    return 0;
}

/* 
When you first encounter this problem, it requires a lot of thinking but it's solution is interesting and fairly simple.
We can achieve our result by folding left half onto right half of bits and repeating until we are left with only 1 bit.
Every line:
    - creates a mask for right half of bits, computes &AND with x which sets left half of bits to zero
    - shifts x by half the places right (UNSIGNED x, so that we achieve logical shift!)
    - performs ^XOR on two values, cancelling overlapped one-bits out

I've printed binary output for every step above to understand it easier:

Our x in binary:
1010 1011 1100 1101 1110 1111 0111 1000
1st step:
0000 0000 0000 0000 0100 0100 1011 0101
2nd step:
0000 0000 0000 0000 0000 0000 1111 0001
3rd step:
0000 0000 0000 0000 0000 0000 0000 1110
4th step:
0000 0000 0000 0000 0000 0000 0000 0001
5th step:
0000 0000 0000 0000 0000 0000 0000 0001

One bits will eventualy cancel each-other out, if there are even number of them, every one-bit "will find it's pair" and 0 will be left.
*/