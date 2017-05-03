class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if ( strs.empty() ) return string();
        string prefix = strs[0];
        int len = prefix.size();
        for ( int i=1, j; i!=strs.size(); ++i ) {
            for ( j=0; j!=len; ++j )
                if ( prefix[j] != strs[i][j] ) break;
            len = j;
        }
        return prefix.substr(0, len);
    }
};
