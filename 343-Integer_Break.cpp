residualclass Solution {
public:
    int integerBreak(int n) {
        if ( n == 2 ) return 1;
        if ( n == 3 ) return 2;
        if ( n == 4 ) return 4;
        int power = n / 3, residual = n % 3;
        switch ( residual ) {
            case 0: return int(pow(3, power));
            case 1: return int(pow(3, power-1)) * 4;
            default: return int(pow(3, power)) * 2;
        }
    }
};
