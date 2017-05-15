class Solution {
    set<vector<int>> vset;
    void helper(const vector<int>& candidates, int index, int current_sum, vector<int> combination, int target) {
        if ( current_sum > target ) return;
        if ( current_sum == target ) {
            sort(combination.begin(), combination.end());
            vset.insert(combination);
            return;
        }
        if ( index == candidates.size() ) return;
        helper(candidates, index+1, current_sum, combination, target);
        combination.push_back(candidates[index]);
        helper(candidates, index+1, current_sum+candidates[index], combination, target);
    }
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        this->vset.clear();
        sort(candidates.begin(), candidates.end());
        helper(candidates, 0, 0, vector<int>(), target);
        return vector<vector<int>>(vset.begin(), vset.end());
    }
};
