class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {

        int n = nums.size();
        if(n<3)return 0;
        int currDiff = nums[1]- nums[0];

        int l =0;
        int count =0;

        for(int r =1; r<n; r++){

            if(nums[r] - nums[r-1] != currDiff){
                int len = (r-1)-l+1;
                if(len>=3){
                    count += (len-1)*(len-2)/2;
                }
                l = r-1;
                currDiff = nums[r] - nums[r-1];
            }
        }

        // handling last segment 
        int len = (n-1)-l+1;
        if(len>=3){
            count+= (len-1)*(len-2)/2;
        }
        
        return count;
    }
};
