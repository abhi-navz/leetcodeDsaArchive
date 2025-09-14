class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int n = matrix.size(); // row size
        int m = matrix[0].size(); // col size

       // in this approach we are gonna use the first row and first col as the marker itself.
       // But since the first row and firstcol will be ovewritten as marker we need to specify before hand if the first row and first col will be needed to be zereod later, we can use boolean varialble to track that. 

       bool firstRow = false, firstCol = false;

       // checking if first row needs to be zeroed

       for(int j =0; j<m; j++){
        if(matrix[0][j] == 0){
            firstRow = true;
        }
       }

       // checking if first col needs to be zeroed

       for(int i =0; i<n; i++){
        if(matrix[i][0] == 0){
            firstCol = true;
        }
       }

       // using first row and col as markers

       for(int i = 1; i<n; i++){
        for(int j = 1; j<m; j++){
            if(matrix[i][j] == 0){
                matrix[i][0] = 0; // row mark
                matrix[0][j] = 0; // col mark

            }
        }
       }

       // applying theese markers

       for(int i =1; i<n; i++){
        for(int j =1; j<m; j++){
            if(matrix[i][0] == 0 || matrix [0][j] == 0){
                matrix[i][j] = 0;
            }
        }
       }

       // fixing the first Row if needed 
       if(firstRow){
        for(int j =0; j<m; j++){
            matrix[0][j] = 0;
        }
       }

        // fixing the first Col if needed 
       if(firstCol){
        for(int i =0; i<n; i++){
            matrix[i][0] = 0;
        }
       }
       
        
    }
};
