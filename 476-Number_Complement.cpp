class Solution {
public:
    int findComplement(int num) {
        int full = ~0;
        while ( full & num ) full <<= 1;
        return full ^ ~num;
    }
};
