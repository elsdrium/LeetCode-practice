class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        if ( nums.size() < 2 ) return nums.size();
        int result = 1, i=1;
        while ( i != nums.size() && nums[i] == nums[i-1] ) ++i;
        bool flag = (nums[i] - nums[i-1] > 0);
        for ( result += (i != nums.size()); i!=nums.size(); ++i ) {
            if ( nums[i] == nums[i-1] ) continue;
            if ( bool(nums[i] - nums[i-1] > 0) != flag ) {
                flag = (nums[i] - nums[i-1] > 0);
                ++result;
            }
        }
        return result;
    }
};
