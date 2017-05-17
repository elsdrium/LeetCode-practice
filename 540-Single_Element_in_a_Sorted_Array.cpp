class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int i = 1, prev = nums[0], dup = 1;
        while ( i!= nums.size() ) {
            while ( nums[i] == prev ) ++dup, ++i;
            if ( dup == 1 ) return prev;
            prev = nums[i], dup = 0;
        }
        return numeric_limits<int>::min();
    }
};
