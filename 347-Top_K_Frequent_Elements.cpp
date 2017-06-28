class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> cnt;
        vector<int> result;
        for ( auto &n : nums ) {
            if ( cnt.find(n) == cnt.end() ) cnt[n] = 1;
            else ++cnt[n];
        }
        vector<pair<int, int>> vec(cnt.begin(), cnt.end());
        nth_element(vec.begin(), vec.begin()+k-1, vec.end(),
            [&](pair<int, int> &a, pair<int, int> &b) { return a.second > b.second; });
        for ( int i = 0; i < k; ++i ) result.push_back(vec[i].first);
        return result;
    }
};
