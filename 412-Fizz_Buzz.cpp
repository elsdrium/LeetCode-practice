class Solution {
public:
    vector<string> fizzBuzz(int n) {
        ostringstream oss;
        vector<string> result;
        for ( int i=1; i<=n; ++i ) {
            oss.str("");
            oss.clear();
            if ( i % 3 == 0 ) oss << "Fizz";
            if ( i % 5 == 0 ) oss << "Buzz";
            if ( i % 3 && i % 5 ) oss << i;
            result.push_back(oss.str());
        }
        return result;
    }
};
