class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {

        int m = matrix.size();
        int n = matrix[0].size();

        if (m == 0 || n == 0) {
            return false;
        }

        int row = 0, col = n - 1;
        while (row < m && col >= 0) {
            if (matrix[row][col] == target) {
                return true;
            }
            if (matrix[row][col] > target) {
                // go left;
                col = col - 1;

            }else{
                // curr < taget : go down
                row = row + 1;
            }
        }

        return false;
    }
};
