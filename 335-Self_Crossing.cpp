class Solution {
public:
    bool isSelfCrossing(vector<int>& x) {
        if ( x.size() < 4 ) return false;
        if ( x.size() == 4 ) return x[0] >= x[2] && x[1] <= x[3];
        
        bool outside(x[0] < x[2] && x[1] < x[3]);
        for ( int i=4; i<x.size(); ++i ) {
            if ( outside ) {
                if ( x[i] <= x[i-2] ) outside = false;
            }
            else {
                if ( x[i] >= x[i-2] ) return true;
                if ( i == 4 && x[1] - x[3] == 0 && x[0] - x[2] + x[4] >= 0 ) return true; // the 5-th step is a special case
                if ( i > 4 && x[i-1] >= x[i-3] - x[i-5] && x[i] >= x[i-2] - x[i-4] && x[i-2] > x[i-4] ) return true;
            }
        }

        return false;
    }
};
