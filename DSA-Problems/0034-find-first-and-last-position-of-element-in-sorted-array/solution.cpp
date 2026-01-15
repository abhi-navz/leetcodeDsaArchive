class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {

        // finding the first position of the target;

        int low = 0, high = nums.size()-1;
        int first = -1,second = -1;
        vector<int>res(2);

        while(low<=high){
            int mid = low + (high - low) / 2;

            if(nums[mid]>=target){
                if(nums[mid] == target){
                    first = mid;
                }


                high = mid-1; // go left
            }else{
                low = mid+1;
            }

        }
        res[0] = first;


        // finding the last index;
        low = 0; high = nums.size()-1;
        

        while(low <= high){
            int mid = low + (high - low) / 2;


            if(nums[mid]<= target){
                if(nums[mid] == target){
                    second = mid;
                }

                low = mid+1; // go right
            }else{
                high = mid-1; 
            }
        }
        res[1] = second;


        return res;
        
    }
};
