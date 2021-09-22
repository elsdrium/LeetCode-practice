class Solution {
public:
    string convert(string s, int numRows) {
        if ( numRows == 1) return s;

        int step = (numRows-2)*2 + 2;
        int last, temp_last = s.size()/step + (s.size()%step>0);
        string result(s.size(), '~');
        for ( int i=0; i*step<s.size(); ++i) result[i] = s[i*step];
        for ( int i=1; i<numRows-1; ++i ) {
            last = temp_last;
            for ( int j=0; i+j*step<s.size(); ++j ) {
                result[last+j*2] = s[i+j*step];
                ++temp_last;
                if ( j*step+(step-i) < s.size() ) {
                    result[last+j*2+1] = s[j*step+(step-i)];
                    ++temp_last;
                }
            }
        }
        last = temp_last;
        for ( int i=0; numRows-1+i*step<s.size(); ++i) result[last+i] = s[numRows-1+i*step];
        return result;
    }
};
