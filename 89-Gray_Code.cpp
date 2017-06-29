class Solution {
public:
    vector<int> grayCode(int n) {
        vector<int> result(1<<n);
        for ( int i = 0; i < n; ++i )
            for ( int j = (1<<i) - 1; j >= 0; --j )
                result[(1<<(i+1))-j-1] = (1<<i) | result[j];
        return result;
    }
};
