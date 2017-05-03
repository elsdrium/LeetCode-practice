class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        vector<int> temp(m+n);
        int i=0, j=0;
        while ( true ) {
            if ( i == m ) {
                for ( ; j!=n; ++j ) temp[i+j] = nums2[j];
                break;
            }
            if ( j == n ) {
                for ( ; i!=m; ++i ) temp[i+j] = nums1[i];
                break;
            }
            if ( nums1[i] > nums2[j] ) {
                temp[i+j] = nums2[j];
                ++j;
            }
            else {
                temp[i+j] = nums1[i];
                ++i;
            }
        }
        nums1.swap(temp);
    }
};
