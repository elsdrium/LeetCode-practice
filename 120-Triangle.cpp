class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int temp_j, temp;
        vector<int> dp(triangle.size());
        dp[0] = triangle[0][0];
        for ( int i=1; i!=triangle.size(); ++i ) {
            for ( int j=0; j<=i; ++j ) {
                if ( j == 0 ) {
                    temp_j = dp[j];
                    dp[j] += triangle[i][j];
                }
                else if ( j == i )
                    dp[j] = temp_j + triangle[i][j];
                else {
                    temp = dp[j];
                    dp[j] = min(temp_j, dp[j]) + triangle[i][j];
                    temp_j = temp;
                }
            }
        }
        return *min_element(dp.begin(), dp.end());
    }
};
