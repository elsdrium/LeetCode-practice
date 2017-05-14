class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int start = 0, len = 0, maximum;
        while ( start < nums.size()-1 && nums[start] <= nums[start+1] ) ++start;
        maximum = nums[start];
        for ( int i=start; i<nums.size(); ++i ) {
            while ( start >= 0 && nums[i] < nums[start] ) --start;
            if ( nums[i] < maximum || (i < nums.size()-1 && nums[i] > nums[i+1]) )
                len = i - start;
            if ( nums[i] > maximum ) maximum = nums[i];
        }
        return len;
    }
};
