class Solution {
public:
    int removeDuplicates(vector<int>& nums) {

        //optimal solution: Two pointer approach

        int n = nums.size();
        if(n==0){
            return 0;
        }

        int index = 1; // position for next unique elements
        for(int i =1;i<n; i++){
            if(nums[i] != nums[i-1]){
                nums[index] = nums[i];
                index++;
            }
        }
        return index;
        
    }
};
