class Solution {
public:
    bool checkRecord(string s) {
        int a_cnt = 0;
        for ( char &c : s ) {
            switch(c) {
            case 'A':
                a_cnt++;
                break;
            default:
                break;
            }
        }
        return (a_cnt < 2 && s.find("LLL") == string::npos);
    }
};
