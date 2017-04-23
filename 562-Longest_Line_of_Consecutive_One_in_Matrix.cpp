class Solution {
public:
    int longestLine(vector<vector<int>>& M) {
        if ( M.empty() ) return 0;
        vector<int> vertical(M[0].size());
        vector<vector<int>> diagonal(M.size(), vector<int>(M[0].size())),
                            antidiagonal(M.size(), vector<int>(M[0].size()));
        int len = 0;
        for ( int i=0; i!=M.size(); ++i ) {
            for ( int j=0, h=0; j!=M[0].size(); ++j ) {
                if ( M[i][j] ) {
                    if ( ++h > len ) len = h;
                    if ( ++vertical[j] > len ) len = vertical[j];
                    diagonal[i][j] = (i>0 && j>0) ? diagonal[i-1][j-1] + 1 : 1;
                    if ( diagonal[i][j] > len ) len = diagonal[i][j];
                    antidiagonal[i][j] = (i>0 && j<M[0].size()-1) ? antidiagonal[i-1][j+1] + 1 : 1;
                    if ( antidiagonal[i][j] > len ) len = antidiagonal[i][j];
                }
                else {
                    h = 0;
                    vertical[j] = 0;
                }
            }
        }
        return len;
    }
};
