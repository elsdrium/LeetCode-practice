class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> ans;
        if ( s.empty() || words.empty() ) return ans;

        unordered_map<string, int> table;
        for ( auto &word : words ) {
            if ( table.find(word) == table.end() )
                table[word] = 1;
            else
                table[word]++;
        }
        int start, curr, len = words[0].size();
        string hot;
        for ( int i = 0; i < len; ++i ) {
            start = i, curr = i;
            while ( start + len*words.size() <= s.size() ) {
                hot = s.substr(curr, len);
                if ( table.find(hot) == table.end() ) {
                    while ( start < curr ) {
                        table[s.substr(start, len)]++;
                        start += len;
                    }
                    curr += len;
                    start += len;
                }
                else {
                    table[hot]--;
                    curr += len;
                    while ( table[hot] < 0 ) {
                        table[s.substr(start, len)]++;
                        start += len;
                    }
                    if ( curr - start == len*words.size() ) {
                        ans.push_back(start);
                        table[s.substr(start, len)]++;
                        start += len;
                    }
                }
            }
            while ( start < curr ) {
                table[s.substr(start, len)]++;
                start += len;
            }
        }
        return ans;
    }
};

static const auto ___ = [](){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return nullptr;
}();
