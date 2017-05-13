class Solution {
public:
    bool isIsomorphic(string s, string t) {
        char mapping[1<<sizeof(char)*8] = {0};
        char inverse[1<<sizeof(char)*8] = {0};
        for( int i=0; i!=s.size(); ++i ) {
            if ( mapping[s[i]] || inverse[t[i]] ) {
                if ( mapping[s[i]] != t[i] || inverse[t[i]] != s[i] )
                    return false;
            }
            else {
                mapping[s[i]] = t[i];
                inverse[t[i]] = s[i];
            }
        }
        return true;
    }
};
