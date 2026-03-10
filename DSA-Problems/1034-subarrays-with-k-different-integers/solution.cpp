class Solution {
public:

    int atMost(vector<int>&nums, int k){
        if(k<0) return 0;

        int l =0; 
        unordered_map<int,int>mpp;
        
        int subArrCount =0;

        for(int r =0; r<nums.size(); r++){

            mpp[nums[r]]++;

            while(mpp.size()>k){
                mpp[nums[l]]--;
                if(mpp[nums[l]] == 0){
                    mpp.erase(nums[l]);
                }
                l++;
            }

            
            subArrCount += r-l+1;
        }
        return subArrCount ;
    }
    int subarraysWithKDistinct(vector<int>& nums, int k) {

        return atMost(nums,k) - atMost(nums, k-1);
        
    }
};
