class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        vector<vector<int>> dp(grid);
        int i, j;
        dp[0][0] = grid[0][0];
        for ( i=1; i!=grid.size(); ++i ) dp[i][0] = dp[i-1][0] + grid[i][0];
        for ( j=1; j!=grid[0].size(); ++j ) dp[0][j] = dp[0][j-1] + grid[0][j];
        for ( i=1; i!=grid.size(); ++i ) {
            for ( j=1; j!=grid[0].size(); ++j ) {
                dp[i][j] = min(dp[i-1][j], dp[i][j-1]) + grid[i][j];
            }
        }
        return dp[grid.size()-1][grid[0].size()-1];
    }
};
