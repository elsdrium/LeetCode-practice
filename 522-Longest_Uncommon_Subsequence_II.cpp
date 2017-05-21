class Solution {
    bool is_sub(const string &a, const string &b) {
        if ( a.size() == b.size() ) return a == b;
        for ( int i=0, j=0; i!=a.size(); ++i ) {
            if ( a[i] == b[j] )
               if ( ++j == b.size() ) return true;
        }
        return false;
    }
public:
    int findLUSlength(vector<string>& strs) {
        sort(strs.begin(), strs.end(),
            [&](string a, string b){ return a.size() > b.size(); });
        int i = 0;
        bool found;
        while ( true ) {
            found = true;
            for ( int j=0; j!=strs.size() && strs[j].size()>=strs[i].size(); ++j ) {
                if ( i != j && is_sub(strs[j], strs[i]) ) {
                    found = false;
                    break;
                }
            }
            if ( found ) return strs[i].size();
            if ( ++i == strs.size() ) break;
        }
        return -1;
    }
};
