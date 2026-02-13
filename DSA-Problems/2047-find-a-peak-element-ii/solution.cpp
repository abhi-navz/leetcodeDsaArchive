class Solution {
public:
    vector<int> findPeakGrid(vector<vector<int>>& mat) {

        int m = mat.size();   
        int n  = mat[0].size();
        

        if(m == 1 and n ==1){
            return {0,0};
        }

        int low =0, high = n-1; // columns;

        while(low<=high){
            int mid = low+(high-low)/2;

            int maxRow =0;
            for(int i =1; i<m; i++){
                if(mat[i][mid]> mat[maxRow][mid]){
                    maxRow = i;
                }
            }

            int curr = mat[maxRow][mid];

            int left = (mid>0)? mat[maxRow][mid-1]: -1;
            int right = (mid<n-1) ? mat[maxRow][mid+1] :  -1;

            if(curr>left && curr>right){
                return {maxRow,mid};
            }

            if(right >  curr){
                low = mid+1;
            }else{
                high = mid-1;
            }
        }
        return {-1,-1};
       
        
    }
};
