class Solution {
public:
    string toHex(int num) {
        int i = 28;
        string result;
        char mapping[16] = {
            '0', '1', '2', '3', '4', '5', '6', '7',
            '8', '9', 'a', 'b', 'c', 'd', 'e', 'f'};
        while ( i > 0 && (num & 15<<i) == 0 )
            i -= 4;
        while ( i >= 0 ) {
            result.push_back(mapping[static_cast<unsigned>(num & 15<<i)>>i]);
            i -= 4;
        }
        return result;
    }
};
