class Solution {
public:
    bool isScramble(string s1, string s2) {
        if ( s1 == s2 ) return true;
        int rec[26] = {0};
        for ( int i=0; i!=s1.size(); ++i ) {
            ++rec[s1[i]-'a'];
            --rec[s2[i]-'a'];
        }
        for ( int &elem : rec )
            if ( elem ) return false;
        for ( int i=1; i<s1.size(); ++i ) {
            if ( isScramble(s1.substr(0, i), s2.substr(0, i)) && isScramble(s1.substr(i, s1.size()-i), s2.substr(i, s2.size()-i)) )
                return true;
            if ( isScramble(s1.substr(0, i), s2.substr(s1.size()-i, i)) &&
                 isScramble(s1.substr(i, s1.size()-i), s2.substr(0, s2.size()-i)) )
                return true;
        }
        return false;
    }
};
