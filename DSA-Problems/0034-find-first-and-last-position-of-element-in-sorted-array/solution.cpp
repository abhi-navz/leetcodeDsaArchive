class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {

        int n = nums.size();
        int st=-1, end =-1;
        int low=0, high = n-1;

        // finding the first pos

        while(low<=high){
            int mid = low + (high - low)/2;
            if(nums[mid]<target){
                low = mid+1;

            }else if(nums[mid]>target){
                high = mid-1;

            }
            else{
                st = mid;
                // go left to check if there's any early occurentce
                high = mid-1;
            }
        }
        
        low =0;
        high = n-1;
        // finding the last pos

        while(low<=high){
            int mid = low + (high - low)/2;
            if(nums[mid]<target){
                low = mid+1;

            }else if(nums[mid]>target){
                high = mid-1;

            }
            else{
                end = mid;
                // go right to check if there's any early occurentce
                low = mid+1;
            }
        }

        return {st,end};
    }
};
