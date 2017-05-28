class Solution {
public:
    int findIntegers(int num) {
        vector<int> cnt({1, 1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89, 144, 233, 377, 610, 987, 1597, 2584,
        4181, 6765, 10946, 17711, 28657, 46368, 75025, 121393, 196418, 317811, 514229, 832040, 1346269});
        string bs = std::bitset<32>(num).to_string();
        bs = bs.substr(bs.find('1'), bs.size()-bs.find('1'));
        int result = cnt[bs.size()+1] + int(bs.find("11") == bs.npos);
        for ( int i=1; i!=bs.size(); ++i ) {
            if ( bs[i] == '1' ) {
                if ( bs[i-1] == '0' )
                    result += cnt[bs.size()-i+1];
                else {
                    bs[i] = '0';
                    if ( i != bs.size() - 1 ) bs[i+1] = 'Q';
                    else result += int(bs.find("11") == bs.npos);
                }
            }
            if ( bs[i] == 'Q' ) {
                result += cnt[bs.size()-i+2];
                break;
            }
        }
        return result;
    }
};
