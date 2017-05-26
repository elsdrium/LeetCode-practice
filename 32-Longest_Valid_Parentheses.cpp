class Solution {
public:
    int longestValidParentheses(string s) {
        int result = 0, curr_start = numeric_limits<int>::max();
        vector<int> istack; istack.reserve(s.size());
        vector<int> sstack; sstack.reserve(s.size());
        for ( int i=0; i!=s.size(); ++i ) {
            if ( s[i] == ')' ) {
                if ( istack.empty() ) curr_start = numeric_limits<int>::max();
                else {
                    curr_start = min({istack.back(), sstack.back(), curr_start});
                    result = max(result, i-curr_start+1);
                    istack.pop_back();
                    sstack.pop_back();
                }
            }
            else {
                istack.push_back(i);
                sstack.push_back(curr_start);
                curr_start = numeric_limits<int>::max();
            }
        }
        return result;
    }
};
