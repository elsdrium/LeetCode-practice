class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int cnt = 0, i, r = 0, full_cnt = 0;
        vector<int> row_cnt(matrix.size());
        while ( true ) {
            for ( i=full_cnt, r=full_cnt; i!=matrix.size(); ++i ) {
                if ( matrix[r][row_cnt[r]] > matrix[i][row_cnt[i]] )
                    r = i;
            }
            if ( ++cnt == k ) return matrix[r][row_cnt[r]];
            if ( ++row_cnt[r] == matrix[r].size() ) ++full_cnt, ++r;
        }
        return matrix[r][row_cnt[r]];
    }
};
