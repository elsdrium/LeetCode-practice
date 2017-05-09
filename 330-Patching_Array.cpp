class Solution {
public:
    int minPatches(vector<int>& nums, int n) {
        int index = 0, result = 0;
        long long sum = 0;
        while ( sum < n ) {
            if ( nums.size() && index != nums.size() && nums[index] <= sum + 1 ) sum += nums[index++];
            else {
                result++;
                sum = (sum<<1) + 1;
            }
        }
        return result;
    }
};
