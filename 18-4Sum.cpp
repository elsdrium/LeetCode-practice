class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        unordered_map<int, list<pair<int, int>>> two_sum;
        set<vector<int>> svi;
        vector<vector<int>> result;
        for ( int i = 0; i < nums.size(); ++i )
            for ( int j = i+1; j < nums.size(); ++j )
                two_sum[nums[i]+nums[j]].push_back({i, j});
        for ( auto &p : two_sum ) {
            if ( two_sum.find(target-p.first) == two_sum.end() ) continue;
            for ( auto &p1 : p.second )
                for ( auto &p2 : two_sum[target-p.first] ) {
                    vector<int> temp = {p1.first, p1.second, p2.first, p2.second};
                    if ( set<int>(temp.begin(), temp.end()).size() < 4 )
                        continue;
                    for_each(temp.begin(), temp.end(), [&](int &n) {n = nums[n];});
                    sort(temp.begin(), temp.end());
                    svi.insert(temp);
                }
        }
        for ( auto &si : svi )
            result.emplace_back(si.begin(), si.end());
        return result;
    }
};
