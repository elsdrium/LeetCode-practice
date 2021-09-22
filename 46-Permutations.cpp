class Solution {
public:
    void dfs(vector<vector<int>>& ans, vector<int>& nums, int index) {
        if ( index == nums.size() ) {
            ans.push_back(nums);
            return;
        }

        for( int i=index; i<nums.size(); ++i ) {
            swap(nums[index], nums[i]);
            dfs(ans, nums, index+1);
            swap(nums[index], nums[i]);
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        ans.reserve(2<<nums.size());
        dfs(ans, nums, 0);
        return ans;
    }
};
