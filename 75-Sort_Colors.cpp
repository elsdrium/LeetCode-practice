class Solution {
public:
    void sortColors(vector<int>& nums) {
        int red_cnt = 0, white_cnt = 0, blue_cnt = 0;
        for ( int &n : nums )
            switch ( n ) {
                case 0:
                    ++red_cnt; break;
                case 1:
                    ++white_cnt; break;
                default:
                    ++blue_cnt;
            }
        for ( int i=0; i!=red_cnt; ++i ) nums[i] = 0;
        for ( int i=red_cnt; i!=white_cnt+red_cnt; ++i ) nums[i] = 1;
        for ( int i=red_cnt+white_cnt; i!=blue_cnt+red_cnt+white_cnt; ++i ) nums[i] = 2;
    }
};
