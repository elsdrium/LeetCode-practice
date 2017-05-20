class NumArray {
    vector<int> partial_sum;
public:
    NumArray(vector<int> nums) : partial_sum(move(nums)) {
        for ( int i=0, sum=0; i!=partial_sum.size(); ++i ) {
            sum += partial_sum[i];
            partial_sum[i] = sum;
        }
    }
    
    int sumRange(int i, int j) {
        return partial_sum[j] - (i > 0 ? partial_sum[i-1] : 0);
    }
};
