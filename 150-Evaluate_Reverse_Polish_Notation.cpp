class Solution {
    bool isNumber(string s) {
        if ( s.empty() ) return false;
        if ( s.size() > 1 ) return true;
        return s[0] <='9' && s[0] >= '0';
    }
    int str2int(string s) {
        int result;
        istringstream iss(s);
        iss >> result;
        return result;
    }
    string int2str(int i) {
        ostringstream oss;
        oss << i;
        return oss.str();
    }
public:
    int evalRPN(vector<string>& tokens) {
        list<string> token_stack;
        int temp;
        string lhs, rhs;
        for ( auto& token : tokens ) {
            if ( isNumber(token) )
                token_stack.push_back(token);
            else {
                rhs = token_stack.back();
                token_stack.pop_back();
                lhs = token_stack.back();
                token_stack.pop_back();
                switch ( token[0] ) {
                    case '+':
                        temp = str2int(lhs) + str2int(rhs); break;
                    case '-':
                        temp = str2int(lhs) - str2int(rhs); break;
                    case '*':
                        temp = str2int(lhs) * str2int(rhs); break;
                    case '/':
                        temp = str2int(lhs) / str2int(rhs); break;
                }
                token_stack.push_back(int2str(temp));
            }
        }
        return str2int(token_stack.back());
    }
};
