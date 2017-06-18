class Solution {
public:
    int maxDistance(vector<vector<int>>& arrays) {
        int result = 0;
        for ( int i=0; i!=arrays.size(); ++i ) {
            for ( int j=i+1; j!=arrays.size(); ++j ) {
                if ( abs(arrays[i].front()-arrays[j].back()) > result )
                    result = abs(arrays[i].front()-arrays[j].back());
                if ( abs(arrays[j].front()-arrays[i].back()) > result )
                    result = abs(arrays[j].front()-arrays[i].back());
            }
        }
        return result;
    }
};
