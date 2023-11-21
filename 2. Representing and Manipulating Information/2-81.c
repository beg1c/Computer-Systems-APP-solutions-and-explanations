/* 
2.81 Write C expressions to generate the bit patterns that follow, where ak represents k repetitions of symbol a. Assume
a w-bit data type. Your code may containt references to parameters j and k, representing the values of j and k,
but not a parameter representing w.

A. 1^w-k 0^k
B. 0^w-k-j 1^k 0^j
*/

int A(int k) {
    return -1 << k;
}

int B(int k, int j) {
    return ~(-1 << k) << j;
}

/* 
A. is pretty straightforward because we only have k. Let's imagine our scenario for w = 8 and k = 2. For those two values, we
should get number: 1111 1100. If we had k = 6, we would get 1100 0000. It is easy to observe that we can compute our result by
shifting -1 (all ones) left k places.

B. Lets imagine w = 8, k = 6 and j = 1. We should get: 0111 1110. If we imagine k = 2 and j = 2, we should get number:
0000 1100. We can notice that we have to fill with 'j' zeroes from right side, meaning that at some point we have to shift
left by 'j' places. Before 'j' zeroes, we need 'k' of ones and we can obtain that by shifting -1 << k places and then performing ~NOT, 
that way we will fill 'k' places with ones. After that we shift left by 'j' places to fill with zeroes.

For example:
1111 1111 / that is -1, shift it left for k = 2
1111 1100 / perform ~NOT
0000 0011 / shift left for j = 2
0000 1100 / our result
*/