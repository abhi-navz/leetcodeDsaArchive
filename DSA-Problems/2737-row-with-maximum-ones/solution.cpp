class Solution {
public:
    vector<int> rowAndMaximumOnes(vector<vector<int>>& mat) {

        int m = mat.size();
        int n = mat[0].size();

        int maxRowSum = -1;
        int maxRowIdx = -1;

        for(int i=0; i<m; i++){
            int rowSum = 0;
            for(int j =0; j<n;j++){
                rowSum += mat[i][j];
            }

            if(rowSum > maxRowSum){
                maxRowSum = rowSum;
                maxRowIdx = i;
            }
        }

        return {maxRowIdx, maxRowSum};


        
    }
};
