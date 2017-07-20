class Solution {
public:
    int nthUglyNumber(int n) {
        static vector<int> ugly_table = {1};
        static int c2 = 0, c3 = 0, c5 = 0;
        if ( n <= 0 ) return 0;
        while ( ugly_table.size() < n ) {
            ugly_table.push_back(min({ugly_table[c2]*2, ugly_table[c3]*3, ugly_table[c5]*5}));
            if ( ugly_table.back() == ugly_table[c2]*2 ) ++c2;
            if ( ugly_table.back() == ugly_table[c3]*3 ) ++c3;
            if ( ugly_table.back() == ugly_table[c5]*5 ) ++c5;
        }
        return ugly_table[n-1];
    }
};
