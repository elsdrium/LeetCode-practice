class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& A) {
        if ( A.size() < 2 ) return 0;
        int diff = A[1]-A[0], count = 1, result = 0;
        for ( int i=2; i!=A.size(); ++i ) {
            if ( A[i] - A[i-1] != diff ) count = 1, diff = A[i] - A[i-1];
            else result += ++count - 1;
        }
        return result;
    }
};
