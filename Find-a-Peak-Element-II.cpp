class Solution {
public:
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        
        int left = 0, right = n - 1;
        
        while (left <= right) {
            int midCol = left + (right - left) / 2;
            
            // Find the max element in midCol
            int maxRow = 0;
            for (int i = 0; i < m; ++i) {
                if (mat[i][midCol] > mat[maxRow][midCol]) {
                    maxRow = i;
                }
            }
            
            int midVal = mat[maxRow][midCol];
            int leftVal = (midCol - 1 >= 0) ? mat[maxRow][midCol - 1] : -1;
            int rightVal = (midCol + 1 < n) ? mat[maxRow][midCol + 1] : -1;
            
            if (midVal > leftVal && midVal > rightVal) {
                // Peak found
                return {maxRow, midCol};
            } else if (rightVal > midVal) {
                // Move right
                left = midCol + 1;
            } else {
                // Move left
                right = midCol - 1;
            }
        }
        
        return {-1, -1}; // Should never happen if input is valid
    }
};
