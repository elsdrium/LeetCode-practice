class Solution {
public:
    bool canMeasureWater(int x, int y, int z) {
        if ( !z ) return true;
        if ( z > x + y ) return false;
        if ( !y ) return z == x;
        int r = x % y;
        while ( r ) {
            x = y;
            y = r;
            r = x % y;
        }
        return !(z % y);
    }
};
