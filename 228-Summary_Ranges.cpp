class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> result;
        if ( nums.size() ) {
            int start = nums[0], end = nums[0];
            for ( int i=0; i<=nums.size(); ++i ) {
                if ( i == nums.size() || nums[i] > end + 1 ) {
                    result.push_back(to_string(start) + (end != start ? "->"+to_string(end) : ""));
                    start = nums[i];
                }
                end = nums[i];
            }
        }
        return result;
    }
};
