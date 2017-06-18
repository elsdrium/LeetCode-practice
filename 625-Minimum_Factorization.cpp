class Solution {
public:
    int smallestFactorization(int a) {
        if ( a == 1 ) return 1;
        int d[10] = {0}, i = 9;
        while ( a > 1 ) {
            if ( i < 2 ) return 0;
            if ( a % i ) { --i; continue; }
            a /= i;
            ++d[i];
        }
        a *= i; --d[i];
        while ( i <= 9 ) {
            if ( !d[i] ) { ++i; continue; }
            d[0] = a*10 + i;
            if ( (d[0]-i)/10 - a ) return 0;
            a = d[0];
            --d[i];
        }
        return a;
    }
};
