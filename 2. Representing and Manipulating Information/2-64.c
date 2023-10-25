/* 
2.64 Write code to implement the following function:

Return 1 when any odd bit of x equals 1; 0 otherwise.
    Assume w=32
int any_odd_one(unsigned x);

Your function should follow the bit-level integer coding rules (page 164), 
except that you may assume that data type int has w = 32 bits. 
*/

int any_odd_one(unsigned x)
{   
    return !!(0xAAAAAAAA & x);
}


int main(void) {
    any_odd_one(1);
    return 0;
}

/* 
Let's again think in terms of 4-bit word rather than 32-bit. For our mask we need a value in which every odd bit is 1.
It would look like this 1010. We can represent 1010 as A, and we do just that in our any_odd_function, creating 32-bit
long mask. We then compute &AND with mask and our x, getting either 0 if no odd bit is equal to 1 or some random number
if some bit is equal to 1. We need to format our return to return 1 or 0, not any random number. We do that by calling 
!NOT two times, converting any random number to 0 and then to 1.
*/