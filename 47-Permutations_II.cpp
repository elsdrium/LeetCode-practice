class Solution {
public:
    void dfs(vector<vector<int>>& ans, vector<int>& nums, int index) {
        if ( index+1 == nums.size() ) {
            ans.push_back(nums);
            return;
        }

        for ( int i=index; i<nums.size(); ++i ) {
            if (i != index && nums[i] == nums[index] ) continue;
            swap(nums[i], nums[index]);
            dfs(ans, nums, index+1);
        }

        for ( int i=nums.size()-1; i>=index; --i ) {
            swap(nums[i], nums[index]);
        }
    }

    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> ans;
        ans.reserve(2<<nums.size());
        sort(nums.begin(), nums.end());
        dfs(ans, nums, 0);
        return ans;
    }
};
