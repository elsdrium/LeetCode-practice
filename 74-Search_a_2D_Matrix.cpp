class Solution {
    int matrix_at(const vector<vector<int>>& matrix, int index) {
        return matrix[index/matrix[0].size()][index%matrix[0].size()];
    }
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if ( matrix.empty() || matrix[0].empty() ) return false;
        int begin = 0, end = matrix.size()*matrix[0].size()-1;
        int mid = (begin + end)/2;
        if ( matrix_at(matrix, begin) == target || matrix_at(matrix, end) == target )
            return true;
        while ( matrix_at(matrix, mid) != target ) {
            if ( matrix_at(matrix, mid) > target ) end = mid;
            if ( matrix_at(matrix, mid) < target ) begin = mid;
            if ( end - begin < 2 ) return false;
            mid = (begin + end)/2;
        }
        return true;
    }
};
