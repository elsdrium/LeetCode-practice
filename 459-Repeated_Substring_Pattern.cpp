class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        if ( s.size() < 2 ) return false;
        int len = 1, j;
        while ( len <= s.size()/2 ) {
            if ( s.size() % len ) {
                ++len;
                continue;
            }
            for ( j=len; j!=s.size(); j+=len )
                if ( s.substr(0, len) != s.substr(j, len) ) break;
            if ( j == s.size() ) return true;
            else ++len;
        }
        return false;
    }
};
