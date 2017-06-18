class Solution {
public:
    int maxDistance(vector<vector<int>>& arrays) {
        int low = arrays[0].front(), high = arrays[0].back(), result = 0;
        for ( int i=1; i!=arrays.size(); ++i ) {
            result = max(high - arrays[i].front(), result);
            result = max(arrays[i].back() - low, result);
            low = min(arrays[i].front(), low);
            high = max(arrays[i].back(), high);
        }
        return result;
    }
};
