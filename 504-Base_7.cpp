class Solution {
public:
    string convertToBase7(int num) {
        string result;
        bool negative = false;
        if ( num < 0 ) {
            negative = true;
            num = -num;
        }
        do {
            result = to_string(num % 7) + result;
            num /= 7;
        } while ( num );
        return (negative ? '-'+result : result);
    }
};
