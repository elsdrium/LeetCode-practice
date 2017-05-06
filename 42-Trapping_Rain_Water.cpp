class Solution {
public:
    int trap(vector<int>& height) {
        int water = 0, current_base = numeric_limits<int>::max();
        list<pair<int, int>> stack;
        for ( int i=0; i!=height.size(); ++i ) {
            while ( stack.size() && current_base < height[i] ) {
                if ( stack.back().second <= height[i] ) {
                    water += (stack.back().second - current_base) * (i - stack.back().first - 1);
                    current_base = stack.back().second;
                    stack.pop_back();
                }
                else {
                    water += (height[i] - current_base) * (i - stack.back().first - 1);
                    stack.push_back(make_pair(i, height[i]));
                    current_base = stack.back().second;
                }
            }
            if ( stack.empty() ) stack.push_back(make_pair(i, height[i])), current_base = height[i];
            if ( current_base > height[i] ) {
                current_base = height[i];
                stack.push_back(make_pair(i, height[i]));
            }
            else stack.push_back(make_pair(i, height[i]));
        }
        return water;
    }
};
