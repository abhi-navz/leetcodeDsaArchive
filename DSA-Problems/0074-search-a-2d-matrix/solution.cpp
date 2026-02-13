class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {

        int m = matrix.size();
        int n = matrix[0].size();

        if(m == 0 || n == 0)
            return false;

        

        int low =0, high = m-1;
        

        while(low<=high){
            int mid = low+(high-low)/2;
            if(matrix[mid][0] <= target){
                low = mid+1;
            }else{
                high = mid-1;
            }

        }
        // i = high will have the target element
        if(high < 0)
            return false;

        int st=0 , end = n-1;

        while(st<=end){
            int mid = st+(end-st)/2;
            if(matrix[high][mid] == target)
                return true;
            if(matrix[high][mid]<target){
                st = mid+1;
            }else{
                end = mid-1;
            }
        }
        return false;


        
    }
};
