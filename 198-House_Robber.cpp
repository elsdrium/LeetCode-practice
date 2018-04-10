class Solution {
public:
    int rob(vector<int>& nums) {
        if ( nums.empty() ) return 0;
        vector<int> record(nums);
        if ( nums.size() > 1 ) record[1] = max(nums[0], nums[1]);
        for ( int i = 2 ; i < nums.size() ; ++i ) {
            record[i] = max(record[i-2] + nums[i], record[i-1]);
        }
        return record.back();
    }
};
