class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int i = 0, end = nums.size() - 1;
        while ( i <= end ) {
            if ( nums[i] == i+1 ) {
                ++i;
                continue;
            }
            if ( nums[i] <= 0 || nums[i]-1 > end) {
                swap(nums[i], nums[end--]);
                continue;
            }
            else if ( nums[i] != nums[nums[i]-1] )
                swap(nums[i], nums[nums[i]-1]);
            else ++i;
        }

        for ( i = 0; i < nums.size(); ++i ) {
            if ( nums[i] != i+1 ) return i+1;
        }
        return i+1;
    }
};

static const auto ___ = [](){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return nullptr;
}();
