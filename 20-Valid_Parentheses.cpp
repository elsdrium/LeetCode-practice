class Solution {
public:
    bool isValid(string s) {
        list<char> stack;
        for( char c : s ) {
            switch ( c ) {
                case '(':
                case '{':
                case '[':
                    stack.push_back(c);
                    break;
                case ')':
                    if ( stack.back() != '(' ) return false;
                    stack.pop_back();
                    break;
                case '}':
                    if ( stack.back() != '{' ) return false;
                    stack.pop_back();
                    break;
                case ']':
                    if ( stack.back() != '[' ) return false;
                    stack.pop_back();
                    break;
            }
        }
        return stack.empty();
    }
};
