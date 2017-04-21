class Solution {
public:
    int q;
    int addDigits(int num) {
        q = num / 10;
        while ( q ) {
            num = q + num%10;
            q = num / 10;
        }
        return num;
        
    }
};
