class Solution {
    vector<vector<int>> ptable;
    vector<vector<string>> result;
    void construct_partitions(const string& s, vector<string> p, int start) {
        for ( int len : this->ptable[start] ) {
            vector<string> temp(p);
            temp.push_back(s.substr(start, len));
            if ( start + len != s.size() )
                construct_partitions(s, temp, start+len);
            else
                this->result.push_back(temp);
        }
    }
public:
    vector<vector<string>> partition(string s) {
        this->ptable = vector<vector<int>>(s.size());
        this->result.clear();
        for ( int i=0; i!=s.size(); ++i ) {
            for ( int len=1; len/2<=i && i+len/2<s.size(); len+=2 ) {
                if ( s[i+len/2] != s[i-len/2] ) break;
                this->ptable[i-len/2].push_back(len);
            }
            for ( int len=2; len/2-1<=i && i+len/2<s.size(); len+=2 ) {
                if ( s[i+len/2] != s[i-len/2+1] ) break;
                this->ptable[i-len/2+1].push_back(len);
            }
        }
        construct_partitions(s, vector<string>(), 0);
        return result;
    }
};
