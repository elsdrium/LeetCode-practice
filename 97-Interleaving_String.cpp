class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        if ( s1.size() + s2.size() != s3.size() ) return false;
        vector<vector<int>> d(s1.size()+1, vector<int>(s2.size()+1));
        for ( int i=1; i<=s1.size(); ++i ) d[i][0] = d[i-1][0] + int(s3[d[i-1][0]] == s1[i-1]);
        for ( int j=1; j<=s2.size(); ++j ) d[0][j] = d[0][j-1] + int(s3[d[0][j-1]] == s2[j-1]);
        for ( int i=1; i<=s1.size(); ++i ) {
            for ( int j=1; j<=s2.size(); ++j ) {
                d[i][j] = max(d[i][j-1] + int(s3[d[i][j-1]] == s2[j-1]), d[i-1][j] + int(s3[d[i-1][j]] == s1[i-1]));
            }
        }
        return d[s1.size()][s2.size()] == s3.size();
    }
};
