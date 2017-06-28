class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& matrix) {
        vector<vector<int>> result(matrix.size(), vector<int>(matrix[0].size(), 55667788));
        for ( int i = 0; i < matrix.size(); ++i )
                for ( int j = 0; j < matrix[0].size(); ++j )
                    if ( !matrix[i][j] ) result[i][j] = 0;
        for ( int d = 0, any = 1; any; ++d, any = !any )
            for ( int i = 0; i < matrix.size(); ++i ) {
                for ( int j = 0; j < matrix[0].size(); ++j ) {
                    if ( result[i][j] != d ) continue;
                    if ( i ) result[i-1][j] = min(result[i-1][j], d+1);
                    if ( j ) result[i][j-1] = min(result[i][j-1], d+1);
                    if ( i < matrix.size()-1 ) result[i+1][j] = min(result[i+1][j], d+1);
                    if ( j < matrix[0].size()-1 ) result[i][j+1] = min(result[i][j+1], d+1);
                    any = 0;
                }
            }
        return result;
    }
};
