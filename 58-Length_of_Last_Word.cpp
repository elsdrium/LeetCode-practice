class Solution {
public:
    int lengthOfLastWord(string s) {
        if ( s.empty() ) return 0;
        int i = s.size() - 1, j;
        while ( i >= 0 && s[i] == ' ' ) --i;
        for ( j = i; j >= 0 && s[j] != ' '; --j );
        return i - j;
    }
};
