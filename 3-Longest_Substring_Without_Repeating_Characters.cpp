class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if ( s.empty() ) return 0;
        bool index1[256] = {0};
        int start = 0, ret = 1;
        for ( int i = 0 ; i < s.size() ; ++i ) {
            if ( index1[ static_cast<size_t>(s[i]) ] ) {
                while ( s[start] != s[i] ) index1[ static_cast<size_t>(s[start++]) ] = false;
                index1[ static_cast<size_t>(s[start++]) ] = false;
            }
            else ret = max(ret, i - start + 1);

            index1[ static_cast<size_t>(s[i]) ] = true;
        }
        return ret;
    }
};

static const auto __ = []{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return nullptr;
}();
