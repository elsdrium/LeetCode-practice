class Solution {
public:
    vector<pair<int, int>> reconstructQueue(vector<pair<int, int>>& people) {
        vector<pair<int, int>> result;
        sort(people.begin(), people.end(), [](pair<int, int>& x, pair<int, int>& y) {
                return x.first == y.first ? x.second < y.second : x.first > y.first;
            });
        for ( auto& p : people )
            result.insert(result.begin() + p.second, p);
        return result;
    }
};
