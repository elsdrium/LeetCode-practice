class Solution {
public:
    int distributeCandies(vector<int>& candies) {
        int d[200001] = {0};
        int count = 0;
        for ( int &c : candies )
            if ( !d[c+100000] ) {
                d[c+100000] = 1;
                count++;
            }
        return min(count, static_cast<int>(candies.size()/2));
    }
};
