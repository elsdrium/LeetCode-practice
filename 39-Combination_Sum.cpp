class Solution {
    set<vector<int>> result;
    void dfs(const vector<int>& nums, int target, vector<int> com, int index, int current_sum) {
        if ( current_sum == target ) {
            sort(com.begin(), com.end());
            result.insert(com);
            return;
        }
        if ( index == nums.size() || current_sum > target ) return;
        dfs(nums, target, com, index+1, current_sum);
        com.push_back(nums[index]);
        dfs(nums, target, com, index, current_sum+nums[index]);
        dfs(nums, target, com, index+1, current_sum+nums[index]);
    }
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        dfs(candidates, target, vector<int>(), 0, 0);
        return vector<vector<int>>(result.begin(), result.end());
    }
};
