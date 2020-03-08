class Solution {
public:
    int maxArea(vector<int>& height) {
        int left = 0, right = height.size() - 1, ans = 0;
        while ( left < right ) {
            ans = max(min(height[left], height[right]) * (right - left), ans);
            if ( height[left] < height[right] ) ++left;
            else --right;
        }
        return ans;
    }
};

static int ___ = [](){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return 0;
}();
