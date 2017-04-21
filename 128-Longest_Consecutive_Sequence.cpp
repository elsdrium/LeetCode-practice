class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int ans = 0, len;
        unordered_set<int> s(nums.begin(), nums.end());
        for ( auto v : s ) {
            if ( s.find(v-1) == s.end() ) {
                len = 1;
                while ( s.find(++v) != s.end() ) ++len;
                if ( len > ans ) ans = len;
            }
        }
        return ans;
    }
};
