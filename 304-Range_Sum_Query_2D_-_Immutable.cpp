class NumMatrix {
    vector<vector<int>> region;
public:
    NumMatrix(vector<vector<int>> matrix) : region(move(matrix)) {
        if ( region.empty() ) return;
        int sum;
        for ( int i=0; i!=region.size(); ++i ) {
            sum = 0;
            for ( int j=0; j!=region[0].size(); ++j ) {
                sum += region[i][j];
                region[i][j] = sum;
            }
        }
        for ( int j=0; j!=region[0].size(); ++j ) {
            sum = 0;
            for ( int i=0; i!=region.size(); ++i ) {
                sum += region[i][j];
                region[i][j] = sum;
            }
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        return region[row2][col2]
             - (col1 > 0 ? region[row2][col1-1] : 0)
             + (row1 > 0 && col1 > 0 ? region[row1-1][col1-1] : 0)
             - (row1 > 0 ? region[row1-1][col2] : 0);
    }
};
