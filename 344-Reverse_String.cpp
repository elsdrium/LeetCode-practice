class Solution {
public:
    string reverseString(string s) {
        auto front = s.begin();
        auto back = s.rbegin();
        char temp;
        for (int i=0; i!=s.size()/2; ++i, ++front, ++back) {
            temp = *back;
            *back = *front;
            *front = temp;
        }
        
        return s;
    }
};
