class Solution {
public:
    int firstBadVersion(int n) {
        long long s = 1, m;
        while ( n - s > 1 ) {
            m = (s + n) / 2;
            if ( isBadVersion(m) ) n = m;
            else s = m;
        }
        return isBadVersion(s) ? s : n;
    }
};
