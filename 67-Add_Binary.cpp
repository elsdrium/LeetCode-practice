class Solution {
public:
    string addBinary(string a, string b) {
        if ( !a.size() && !b.size() ) return "0";
        bool flag = false;
        string &c = a.size() > b.size() ? a : b;
        int i;
        for ( i=0; i!=min(a.size(), b.size()); ++i ) {
            if ( flag ) {
                if ( a[a.size()-i-1] == '1' && b[b.size()-i-1] == '1' ) { }
                else if ( ( a[a.size()-i-1] == '1' && b[b.size()-i-1] == '0' )
                       || ( a[a.size()-i-1] == '0' && b[b.size()-i-1] == '1' ) ) c[c.size()-i-1] = '0';
                else {
                    c[c.size()-i-1] = '1';
                    flag = false;
                }
            }
            else {
                if ( a[a.size()-i-1] == '1' && b[b.size()-i-1] == '1' ) {
                    c[c.size()-i-1] = '0';
                    flag = true;
                }
                else if ( ( a[a.size()-i-1] == '1' && b[b.size()-i-1] == '0' )
                       || ( a[a.size()-i-1] == '0' && b[b.size()-i-1] == '1' ) ) c[c.size()-i-1] = '1';
            }
        }
        while ( flag && i != c.size() ) {
            if ( c[c.size()-i-1] == '1' ) {
                c[c.size()-i-1] = '0';
                ++i;
            }
            else {
                c[c.size()-i-1] = '1';
                flag = false;
            }
        }
        return flag ? "1" + c : c;
    }
};
