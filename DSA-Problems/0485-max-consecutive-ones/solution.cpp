class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int n = nums.size();

        int maxStreak = 0;
         int currentStreak =0;

        for(int i =0;i<n; i++){
           
            if(nums[i] == 1){
                currentStreak++;
                maxStreak = max(maxStreak, currentStreak);
            }
            else{
                currentStreak = 0;
            }
        }

        return maxStreak;
        
    }
};
