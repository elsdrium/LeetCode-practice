class Solution {
    int returnResult(bool negative, long long result) {
        result = negative ? -result : result;
        if ( result > numeric_limits<int>::max() ) result = numeric_limits<int>::max();
        if ( result < numeric_limits<int>::min() ) result = numeric_limits<int>::min();
        return result;
    }
public:
    int myAtoi(string str) {
        bool negative = false;
        bool positive = false;
        bool empty_result = true;
        long long result = 0;
        for ( int index=0; index != str.size(); ++index ) {
            if ( str[index] - '0' > 9 || str[index] - '0' < 0 ) {
                switch ( str[index] ) {
                    case ' ':
                        if ( empty_result ) continue;
                        else return returnResult(negative, result);
                    case '-':
                        if ( !negative && !positive && empty_result ) {
                            negative = true;
                            empty_result = false;
                            continue;
                        } else return 0;
                    case '+':
                        if ( !negative && !positive && empty_result ) {
                            positive = true;
                            empty_result = false;
                            continue;
                        } else return 0;
                    default:
                        return returnResult(negative, result);
                }
            }
            empty_result = false;
            result *= 10;
            result += str[index] - '0';
            if ( result > numeric_limits<int>::max() ) break;
        }
        return returnResult(negative, result);
    }
};
