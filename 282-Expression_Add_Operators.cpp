class Solution {
    vector<string> result;
    void foo(int begin, int size, string s, long long cur_ret, long long last_opc, bool opc_flag, const string &num, int target) {
        if ( begin == num.size() ) {
            if ( cur_ret + last_opc == target ) result.push_back(s);
            return;
        }
        string ops = num.substr(begin, size);
        long long op = stoll(ops);
        if ( begin + size < num.size() && num[begin] != '0' ) foo(begin, size+1, s, cur_ret, last_opc, true, num, target);
        if ( s.empty() ) { foo(begin+size, 1, ops, 0, op, true, num, target); return; }
        foo(begin+size, 1, s+"+"+ops, cur_ret+last_opc, op, true, num, target);
        foo(begin+size, 1, s+"-"+ops, cur_ret+last_opc, -op, true, num, target);
        foo(begin+size, 1, s+"*"+ops, cur_ret, (opc_flag ? last_opc : false)*op, true, num, target);
    }
public:
    vector<string> addOperators(string num, int target) {
        result.clear();
        foo(0, 1, string(), 0, 0, false, num, target);
        return result;
    }
};
