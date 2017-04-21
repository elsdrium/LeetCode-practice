class Solution {
public:
    int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D) {
        unordered_map<int, int> AB;
        int temp, result = 0;
        
        for ( int &a : A ) {
            for ( int &b : B ) {
                temp = a + b;
                if ( AB.find(-temp) == AB.end() ) AB[-temp] = 1;
                else AB[-temp] += 1;
            }
        }
        for ( int &c : C ) {
            for ( int &d : D ) {
                temp = c + d;
                if ( AB.find(temp) != AB.end() ) result += AB[temp];
            }
        }
        return result;
    }
};
