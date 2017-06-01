class Solution {
public:
    string nearestPalindromic(string n) {
        int plus1, plus0, minus1, m;
        string ln, rn, p1, p0, m1 = n.substr(1,n.size()-2);
        if ( n.size() < 3 && stoi(n) <= 10 ) return to_string(stoi(n) - 1);
        if ( all_of(n.begin(), n.end(), [&](char c){ return c == '9'; }) ) return "1" + string(n.size()-1, '0') + "1";
        if ( n.front() == '1' && n.back() - '0' < 2 && all_of(m1.begin(), m1.end(), [&](char c){ return c == '0'; }) )
            return string(n.size()-1, '9');
        ln = n.substr(0, n.size()/2 + (n.size() % 2));
        rn = n.substr(n.size()/2 + (n.size() % 2), n.size()/2);
        p0 = ln; reverse(p0.begin(), p0.end());
        plus0 = abs(stoi(p0.substr(n.size() % 2, p0.size() - n.size() % 2)) - stoi(rn));
        p1 = to_string(stoi(ln)+1); reverse(p1.begin(), p1.end());
        plus1 = abs(stoi(p1.substr(n.size() % 2, p1.size() - n.size() % 2)) - stoi(rn) + stoi("1" + string(n.size()/2, '0')));
        m1 = to_string(stoi(ln)-1); reverse(m1.begin(), m1.end());
        if ( m1.substr(n.size() % 2, m1.size() - n.size() % 2).empty() )
            return "101";
        else
            minus1 = abs(stoi(m1.substr(n.size() % 2, m1.size() - n.size() % 2)) - stoi(rn) - stoi("1" + string(n.size()/2, '0')));
        m = min({!plus0 ? numeric_limits<int>::max() : plus0, plus1, minus1});
        if ( m == minus1 ) {
            rn = m1; reverse(m1.begin(), m1.end());
            return m1 + rn.substr(n.size() % 2, rn.size() - (n.size() % 2));
        }
        if ( m == plus0 ) {
            rn = p0; reverse(p0.begin(), p0.end());
            return p0 + rn.substr(n.size() % 2, rn.size() - (n.size() % 2));
        }
        rn = p1; reverse(p1.begin(), p1.end());
        return p1 + rn.substr(n.size() % 2, rn.size() - (n.size() % 2));
    }
};
