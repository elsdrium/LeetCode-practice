class Solution {
public:
    bool isPerfectSquare(int num) {
        int low = 1, mid = min((num+1)/2, 46340), high = num, temp;
        if ( num == 1 ) return true;
        while ( high - low > 1 ) {
            temp = mid*mid;
            if ( temp == num ) return true;
            if ( temp < num ) low = mid;
            else high = mid;
            mid = (high + low) / 2;
        }
        return false;
    }
};
