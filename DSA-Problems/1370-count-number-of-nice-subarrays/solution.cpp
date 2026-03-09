class Solution {
public:
    int atMost(vector<int>&nums, int k){

        int countOdd =0; 
        int subArrCount =0;
        int l =0; 

        for(int r =0; r<nums.size(); r++){

            if((nums[r] & 1) == 1){
                countOdd++;
            }

            while(countOdd>k){

                if((nums[l] & 1 )== 1){
                    countOdd--;
                }
                l++;

            }

            subArrCount += r-l+1;

            


        }
        return subArrCount;
    
    }
    int numberOfSubarrays(vector<int>& nums, int k) {

        return atMost(nums,k) - atMost(nums,k-1);

        
    }
};
