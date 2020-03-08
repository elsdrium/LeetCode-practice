class Solution {
public:
    int splitArray(vector<int>& nums, int m) {
        long h = accumulate(nums.begin(), nums.end(), 0L),
             l = *max_element(nums.begin(), nums.end()),
             mid;
        while ( l < h ) {
            mid = (h+l) / 2;
            if ( check(nums, m, mid) )
                h = mid;
            else
                l = mid + 1;
        }
        return l;
    }

    bool check(vector<int>& nums, int m, const long& trial) {
        long sum = 0, parts = 0;
        for ( auto &n : nums ) {
            sum += n;
            if ( sum > trial ) {
                if ( ++parts >= m ) return false;
                sum = n;
            }
        }
        return true;
    }
};

static const auto ___ = [](){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return nullptr;
}();
