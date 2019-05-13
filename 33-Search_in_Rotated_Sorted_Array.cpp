class Solution {
public:
    int search(vector<int>& nums, int target) {
        if ( nums.empty() ) return -1;
        if ( nums.size() == 1 ) return (nums[0] == target ? 0 : -1);

        int start = 0, end = nums.size()-1, mid = nums.size()/2;
        while ( nums[end] < nums[start] && end - start > 1 ) {
            mid = (start + end)/2;
            if ( nums[mid] <= nums[end] ) end = mid;
            if ( nums[mid] >= nums[start] ) start = mid;
        }
        if ( end - start == 1 ) {
            end = start + nums.size();
            start += 1;
        }

        auto T = [=](int x) { return (x >= nums.size() ? x - nums.size() : x); };
        while ( end - start  > 1 ) {
            mid = (start + end)/2;
            if ( nums[T(mid)] < target ) start = mid;
            if ( nums[T(mid)] > target ) end = mid;
            if ( nums[T(mid)] == target ) return T(mid);
        }
        if ( nums[T(start)] == target ) return T(start);
        if ( nums[T(end)] == target ) return T(end);
        return -1;
    }
};
