class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n = nums.size();
    
        int index =0;

        // keeping the non zero elements first.

        for(int i =0; i<n; i++){
            if(nums[i] !=0){
                nums[index] = nums[i];
                index++;
            }
        }

        // feeling the rest of the array with zeroes

        for(int i = index; i<n; i++){
            nums[i] =0;
        }


        
    }
};
