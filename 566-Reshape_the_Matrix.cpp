class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& nums, int r, int c) {
        int rows = nums.size(), cols = nums.empty() ? 0 : nums[0].size();
        vector<vector<int>> result;
        vector<int> vec;
        if ( rows * cols != r * c ) {
            result = nums;
            return result;
        }
        for ( int i=0, quo, res; i!=r*c; ++i ) {
            quo = i / c, res = i % c;
            if ( !res && quo ) {
                result.push_back(vec);
                vec.clear();
            }
            vec.push_back(nums[i/cols][i%cols]);
        }
        result.push_back(vec);
        return result;
    }
};
