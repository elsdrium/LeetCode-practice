class Solution {
public:
    vector<int> getRow(int rowIndex) {
        int i;
        vector<int> result(rowIndex + 1);
        result[0] = 1;
        for ( int i = 0; i <= rowIndex; ++i )
            for ( int j = i; j; --j )
                result[j] += result[j-1];
        return result;
    }
};
