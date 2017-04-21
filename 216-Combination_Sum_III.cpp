class Solution {
    vector<vector<int>> result;
    void check(vector<int> v, int digit, int cur_sum, int n, int k) {
        if ( v.size() == k )
            if ( cur_sum != n ) return;
            else {
                result.push_back(v);
                return;
            }
        if ( digit > 9 ) return;
        if ( cur_sum + digit > n ) return;
        check(v, digit+1, cur_sum, n, k);
        v.push_back(digit);
        check(v, digit+1, cur_sum+digit, n, k);
    }
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        result = vector<vector<int>>();
        check(vector<int>(), 1, 0, n, k);
        reverse(result.begin(), result.end());
        return result;
    }
};
