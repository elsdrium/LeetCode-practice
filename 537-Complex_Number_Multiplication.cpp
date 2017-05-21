class Solution {
public:
    string complexNumberMultiply(string a, string b) {
        ostringstream oss;
        int a1, a2, b1, b2;
        sscanf(a.c_str(), "%d+%di", &a1, &a2);
        sscanf(b.c_str(), "%d+%di", &b1, &b2);
        oss << a1*b1 - a2*b2 << '+' << a1*b2 + a2*b1 << 'i';
        return oss.str();
    }
};
