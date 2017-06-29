class Solution {
public:
    bool isAnagram(string s, string t) {
        if ( s.size() != t.size() ) return false;
        int cnt[26] = {0};
        for ( int i = 0; i < s.size(); ++i ) {
            ++cnt[s[i] - 'a'];
            --cnt[t[i] - 'a'];
        }
        return !any_of(cnt, cnt+26, [&](int& n) {return n;});
    }
};
