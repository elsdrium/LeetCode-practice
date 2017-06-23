class Solution {
public:
    int minMoves2(vector<int>& nums) {
        nth_element(nums.begin(), nums.begin()+nums.size()/2, nums.end());
        int result = 0, median = nums[nums.size()/2];
        for ( int &n : nums ) {
            result += (n > median ? n - median : median - n);
        }
        return result;
    }
};
