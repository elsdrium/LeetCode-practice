class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        vector<int> result;
        for ( int i = 0; i < nums.size(); ++i ) {
            if ( nums[i] != i+1 ) {
                if ( nums[nums[i]-1] == nums[i] ) nums[i] = 0;
                else {
                    swap(nums[i], nums[nums[i]-1]);
                    --i;
                }
            }
        }
        for ( int i = 0; i < nums.size(); ++i )
            if ( !nums[i] ) result.push_back(i+1);
        return result;
    }
};
