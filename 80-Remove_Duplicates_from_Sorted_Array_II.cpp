class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int i = 0, k;
        while ( i < nums.size() ) {
            if ( !i || nums[i-1] != nums[i] ) k = 0;
            else k++;
            
            if ( k > 1 ) nums.erase(nums.begin()+i);
            else i++;
        }
        return nums.size();
    }
};
