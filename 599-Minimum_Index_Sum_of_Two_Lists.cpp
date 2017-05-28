class Solution {
public:
    vector<string> findRestaurant(vector<string>& list1, vector<string>& list2) {
        unordered_map<string, int> record;
        vector<string> output;
        int min_index_sum = numeric_limits<int>::max();
        for ( int i=0; i!=list1.size(); ++i ) record[list1[i]] = i;
        for ( int i=0; i!=list2.size(); ++i ) {
            if ( record.find(list2[i]) != record.end() ) {
                if ( record[list2[i]] + i < min_index_sum ) {
                    output.clear();
                    min_index_sum = record[list2[i]] + i;
                }
                if ( record[list2[i]] + i <= min_index_sum )
                    output.push_back(list2[i]);
            }
        }
        return output;
    }
};
