class Solution {
    public:
        int divide(int dividend, int divisor) {
            bool bNegative = false;

            long dd(dividend), dr(divisor);
            if ( dd < 0 ) { dd = -dd; bNegative = !bNegative; }
            if ( dr < 0 ) { dr = -dr; bNegative = !bNegative; }
            if ( dr > dd ) return 0;

            long quo = 0, idx = 1;
            while ( dd >= (dr<<1) ) {
                dr <<= 1;
                idx <<= 1;
            }
            while ( idx ) {
                if ( dd >= dr ) {
                    dd -= dr;
                    quo += idx;
                }
                dr >>= 1;
                idx >>= 1;
            }

            if ( quo > static_cast<long>(numeric_limits<int>::max()) && !bNegative )
                quo = numeric_limits<int>::max();

            return bNegative ? -quo : quo;
        }
};

static const auto ___ = [](){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
};
