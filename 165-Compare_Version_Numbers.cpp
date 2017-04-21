class Solution {
public:
    int compareVersion(string version1, string version2) {
        istringstream iss;
        string str;
        list<int> v1, v2;
        int n1, n2;
        
        iss.str(version1);
        while ( getline(iss, str, '.') ) v1.push_back(atoi(str.c_str()));
        
        iss.clear();
        iss.str(version2);
        while ( getline(iss, str, '.') ) v2.push_back(atoi(str.c_str()));
        
        while ( v1.size() || v2.size() ) {
            n1 = 0, n2 = 0;
            if ( v1.size() ) { n1 = v1.front(); v1.pop_front(); }
            if ( v2.size() ) { n2 = v2.front(); v2.pop_front(); }
            
            if ( n1 == n2 ) continue;
            else return ( n1 > n2 ) ? 1 : -1;
        }
        return 0;
    }
};
