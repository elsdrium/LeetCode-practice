class Solution {
    pair<vector<int>, int> merge_sort_count(vector<int>& v, int s, int t) {
        int count = 0, m;
        if ( t == s ) return {vector<int>(1, v[s]), count};
        if ( t - s == 1 ) {
            vector<int> ret({v[s], v[t]});
            count += int(ret[0] > static_cast<long long>(ret[1])*2);
            if ( ret[0] > ret[1] ) swap(ret[0], ret[1]);
            return {ret, count};
        }
        auto ret1 = merge_sort_count(v, s, (s + t)/2), ret2 = merge_sort_count(v, (s + t)/2 + 1, t);
        count = ret1.second + ret2.second;
        vector<int> ret(ret1.first.size() + ret2.first.size()), &vs = ret1.first, &vt = ret2.first;
        if ( vs.back() > static_cast<long long>(vt.front())*2 ) {
            s = vs.size()-1, t = 0;
            while ( t != vt.size() && vs[s] > static_cast<long long>(vt[t])*2 ) ++t;
            --t;
            while ( s >= 0 && t >= 0 && vs[s] > static_cast<long long>(vt[t])*2 ) {
                count += (t + 1);
                --s;
                while ( s >= 0 && t >= 0 && vs[s] <= static_cast<long long>(vt[t])*2 ) --t;
            }
        }

        s = 0, t = 0;
        while ( s != vs.size() && t != vt.size() ) {
            if ( vs[s] > vt[t] ) {
                ret[s+t] = vt[t];
                ++t;
            }
            else {
                ret[s+t] = vs[s];
                ++s;
            }
        }
        while ( s != vs.size() ) { ret[s+t] = vs[s]; ++s; }
        while ( t != vt.size() ) { ret[s+t] = vt[t]; ++t; }
        return {ret, count};
    }
public:
    int reversePairs(vector<int>& nums) {
        return nums.empty() ? 0 : merge_sort_count(nums, 0, nums.size()-1).second;
    }
};
