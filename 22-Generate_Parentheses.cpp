class Solution {
public:
    void generateParenthesisHelper(int n, int open, const string& str, vector<string>& ans) {
        if ( n == 0 ) {
            ans.push_back(str + string(open, ')'));
            return;
        }
        generateParenthesisHelper(n-1, open+1, str+'(', ans);
        if ( open )
            generateParenthesisHelper(n, open-1, str+')', ans);
    }
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        generateParenthesisHelper(n, 0, "", ans);
        return ans;
    }
};

static auto ___ = [](){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return nullptr;
}();
