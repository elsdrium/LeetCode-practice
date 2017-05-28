class Solution {
public:
    int maxCount(int m, int n, vector<vector<int>>& ops) {
        int rmin = m, cmin = n;
        for ( auto &v : ops ) {
            if ( v[0] < rmin ) rmin = v[0];
            if ( v[1] < cmin ) cmin = v[1];
        }
        return rmin * cmin;
    }
};
