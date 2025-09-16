class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {

        int n = matrix.size();
        int m = matrix[0].size();

        int left = 0, right = m-1;
        int top = 0, bottom = n-1;
        
        // vector to store ans;
        vector<int> ans;

        while(left<=right && top<= bottom){

            // going right
            for(int i = left; i<= right; i++){
                ans.push_back(matrix[top][i]);
                
            }
            top++;


            // going down
            for(int i = top; i<= bottom; i++){
            ans.push_back(matrix[i][right]);
                
            }
            right--;

           

            // going left

            if(top<= bottom){
                for(int i= right; i>= left; i--){
                ans.push_back(matrix[bottom][i]);
                }

                bottom --;
            }

            

            // going up
            if( left<= right){

                for(int i = bottom;  i>= top; i--){
                ans.push_back(matrix[i][left]);

                }
                left++;
            }
            

           



        }

        return ans;
        
    }
};
