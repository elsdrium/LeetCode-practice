class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int result = 0, diff = 0;
        unordered_map<int, int> diff_record;
        diff_record[0] = -1;
        for ( int i=0; i!=nums.size(); ++i ) {
            diff += nums[i] ? 1 : -1;
            if ( diff_record.find(diff) == diff_record.end() ) diff_record[diff] = i;
            else
                if ( i - diff_record[diff] > result )
                    result = i - diff_record[diff];
        }
        return result;
    }
};
