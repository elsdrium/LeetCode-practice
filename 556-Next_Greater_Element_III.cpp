class Solution {
public:
    int nextGreaterElement(int n) {
        int m;
        string num = to_string(n), intmax = to_string(numeric_limits<int>::max());
        for ( int i=num.size()-2; i>=0; --i ) {
            if ( num[i] < num[i+1] ) {
                for ( m=i+1 ; m!=num.size()-1 && num[i]<num[m+1] ; ++m );
                swap(num[i], num[m]);
                sort(num.begin()+i+1, num.end());
                if ( num.size() > intmax.size()
                    || (num.size() == intmax.size() && num > intmax) )
                    return -1;
                return stoi(num);
            }
        }
        return -1;
    }
};
