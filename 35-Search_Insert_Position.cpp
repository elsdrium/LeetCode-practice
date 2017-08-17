class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        if ( target > nums.back() ) return nums.size();
        if ( target <= nums.front() ) return 0;
        int start = 0, end = nums.size(), mid;
        while ( end - start > 1 ) {
            mid = (start + end) >> 1;
            if ( target <= nums[mid] ) end = mid;
            else start = mid;
        }
        return end;
    }
};
