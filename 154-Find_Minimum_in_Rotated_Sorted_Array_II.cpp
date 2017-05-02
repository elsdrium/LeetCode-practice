class Solution {
    int foo(const vector<int>& nums, int start, int end) {
        if ( end - start == 1 ) return nums[start];
        if ( end - start == 2 ) return min(nums[start], nums[start+1]);
        if ( nums[start] < nums[end-1]) return nums[start];
        int mid = (start + end)/2;
        if ( nums[start] > nums[mid] ) return foo(nums, start, mid+1);
        if ( nums[mid] > nums[end-1] ) return foo(nums, mid, end);
        return min(foo(nums, start, mid), foo(nums, mid, end));
    }
public:
    int findMin(vector<int>& nums) {
        return foo(nums, 0, nums.size());
    }
};
