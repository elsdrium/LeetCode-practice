class Solution {
public:
    int minDistance(string word1, string word2) {
        vector<vector<int>> d(word1.size()+1, vector<int>(word2.size()+1));
        int i, j;
        for ( i=0; i<=word1.size(); ++i ) d[i][0] = i;
        for ( j=0; j<=word2.size(); ++j ) d[0][j] = j;
        
        for ( i=1; i<=word1.size(); ++i ) {
            for ( j=1; j<=word2.size(); ++j ) {
                if ( word1[i-1] == word2[j-1] ) d[i][j] = d[i-1][j-1];
                else d[i][j] = min({d[i-1][j-1]+1, d[i-1][j]+1, d[i][j-1]+1});
            }
        }
        return d[word1.size()][word2.size()];
    }
};
