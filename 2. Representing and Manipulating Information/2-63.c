/* 
2.63 Fill in code for the following C functions. Function srl performs a logical right shift using an arithmetic right shift (given by
value xsra), followed by other operations not including right shifts or division. Function sra performs an arithmetic right shift using 
a logical right shift (given by value xsrl), followed by other operations not including right shifts or division. You may use the
computation 8*sizeof(int) to determine w, the number of bits in data type int. The shift amount k can range from 0 to w - 1.
*/

unsigned srl(unsigned x, int k) {
    unsigned xsra = (int) x >> k; //Perform shift arithmetically

    int word_size = 8*sizeof(int);
    int mask = ~(-1 << (word_size - k));

    return xsra & mask;
}

int sra(int x, int k) {
    int xsrl = (unsigned) x >> k; //Perform shift logically

    int word_size = 8*sizeof(int);
    int mask = -1 << (word_size - k);
    int check_sign = (1 << (word_size - k)) & x;

    return xsrl ^ (mask & (!check_sign - 1));
}


int main(void) {
    srl(32131, 4);
    sra(32122, 4);
    return 0;
}



/* 
I will use 4-bit long word in this explanation for easier understanding. 

srl function:
Lets say we have 4-bit long word: 1101. If we shift it logically right by two places, we should get: 0011. Problem is, our srl will first shift it arithmetically,
filling with ones and resulting in 1111. We see that our right two bits are okay, so we only need to convert left two bits into zeros. Easiest way to do that is to 
compute &AND on every bit with some mask. For this example, we need 0011 (0011&1111=0011) as mask. We can create a mask that will work on any word size by shifting 
-1 (all ones) left by (word-size - k) places. In particular example that results in: 1111 (-1 decimal) << (4 - 2)  = 1100. Considering we need 0011, not 1100, we
need to perform ~NOT on every bit. In our return value we compute &AND with arithmetically shifted value and our mask.

sra function:
Lets again say that we have 4-bit long word: 1101. Shifting it arithmetically right by two places, we should get 1111. Our function first shifts it logicaly, resulting
in 0011. Using the mask from previous task 1100(without ~NOT) and performing ^XOR, we can get 1111. We now need to account for a scenario in which we have
0 as sign bit, for example in 0101. In that case, we do not need to perform any further changes because arithmetic shift will be the same as logical shift. If we want to
keep zeroes, we need all zeroes in our mask (XOR with zeroes will keep the bits unchanged). How can we check the sign bit without right shifts? We can create 0001 (1),
shift it left by word_size-1 to get 1000 and then compute &AND with our input X. If sign value is 0, we will get 0000 (0) and 1000 (INT_MIN) otherwise. 
Now we only have to decide which mask to use. We need to keep the mask unchanged if check_sign is 1 and use 0 if check_sign is 0.
We can write it like this in our return value: mask & (!check_sign - 1). We first perform !NOT on our check_sign. It yields 0001 if check_bit is 0 and 0000 if check_sign is 1.
When we subtract 1 from that, we get 0000 if our check_sign was 0 and 1111 (because -1 is represented as 1111 in two's complement) if check_sign was 1. Computing &AND
with that and our mask, we either change the mask or keep it the same.
*/