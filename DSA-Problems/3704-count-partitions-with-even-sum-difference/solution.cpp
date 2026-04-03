class Solution {
public:
    int countPartitions(vector<int>& nums) {
        int n  = nums.size();
        int totalSum = 0;
        for(int x: nums){
            totalSum += x;
        }
        int leftSum = 0,count = 0;

        for(int i=0; i<n-1; i++){

            leftSum += nums[i];
            int rightSum = totalSum - leftSum;

            if((rightSum -leftSum)% 2 == 0) count++;
        }
        
        return count;
    }
};
