class Solution {
public:
    int candy(vector<int>& ratings) {
        vector<int> downward(ratings.size());
        for ( int i=ratings.size()-2; i>=0; --i )
            if ( ratings[i] > ratings[i+1] ) downward[i] = downward[i+1] + 1;
        int prev = downward.empty() ? 0 : downward[0];
        int result = ratings.size() + prev;
        for ( int i=1; i<ratings.size(); ++i ) {
            if ( ratings[i] == ratings[i-1] ) prev = 0;
            if ( downward[i] > prev ) { prev = downward[i]; result += prev; }
            else if ( ratings[i] > ratings[i-1] ) result += ++prev;
            else if ( downward[i] ) { prev = downward[i]; result += prev; }
            else prev = 0;
        }
        return result;
    }
};
