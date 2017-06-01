class Solution {
public:
    bool isUgly(int num) {
        if ( !num ) return false;
        while ( !(num % 2) || !(num % 3) || !(num % 5) ) {
            if ( !(num % 2) ) num /= 2;
            if ( !(num % 3) ) num /= 3;
            if ( !(num % 5) ) num /= 5;
        }
        return num == 1;
    }
};
