class Solution {
public:
    int bitwiseComplement(int n) {
        if(n==0) return 1;
        unsigned mask = ~0;
        while (n & mask) mask <<= 1;
        return ~mask & ~n;
        /*
        n          = 00000101
        mask         = 11111000
        ~mask & ~n = 00000010
        */
    }
};
// same as: https://leetcode.com/problems/complement-of-base-10-integer/
