class Solution {
public:
    bool isMatch(string s, string p) {
        vector<vector<int>> d(p.size()+1, vector<int>(s.size()+1));
        if ( p[0] != '*' ) for ( int j=1; j<=s.size(); ++j ) d[0][j] = numeric_limits<int>::min();
        for ( int i=1; i<=p.size(); ++i ) {
            d[i][0] = min(0, p[i-1]!='*' ? numeric_limits<int>::min() : d[i-1][0]);
            for ( int j=1; j<=s.size(); ++j ) {
                if ( p[i-1] == '*' )
                    d[i][j] = max({d[i-1][j-1], d[i][j-1], d[i-1][j]}) + 1;
                else if ( p[i-1] == '?' || p[i-1] == s[j-1] )
                    d[i][j] = d[i-1][j-1] + 1;
                else
                    d[i][j] = numeric_limits<int>::min();
            }
        }
        return d[p.size()][s.size()] >= 0 && d[p.size()][s.size()] >= s.size();
    }
};

