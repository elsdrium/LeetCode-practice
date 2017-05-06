class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int i, loc, max_area = 0;
        list<pair<int, int>> stack;
        stack.push_back(make_pair(0, 0));
        for ( i=0; i!=heights.size(); ++i ) {
            loc = i;
            if ( heights[i] < stack.back().second )
                while ( heights[i] < stack.back().second ) {
                    loc = stack.back().first;
                    if ( max_area < (i - stack.back().first)*stack.back().second )
                        max_area = (i - stack.back().first)*stack.back().second;
                    stack.pop_back();
                }
            if ( heights[i] > stack.back().second )
                stack.push_back(make_pair(loc, heights[i]));
        }
        while ( stack.size() ) {
            if ( max_area < (i - stack.back().first)*stack.back().second )
                max_area = (i - stack.back().first)*stack.back().second;
            stack.pop_back();
        }
        return max_area;
    }
};
