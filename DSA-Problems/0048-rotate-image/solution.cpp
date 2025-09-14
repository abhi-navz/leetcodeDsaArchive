class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        // to rotate the matrix by 90 degrees clockwise, we'll first transpose the matrix then we'll reverse every row to get the rotated matrix

        int n = matrix.size();

        // transposing : swapping the right half to the left half and we'll get the transpose of the matrix.


        for(int i =0; i<=n-2; i++){
            for(int j = i+1; j<=n-1; j++){
                swap(matrix[i][j], matrix[j][i]);
            }
        }
        
        // reversing the rows 
        for(int i =0; i<n; i++){
            reverse(matrix[i].begin(),matrix[i].end());
        }
    }
};
