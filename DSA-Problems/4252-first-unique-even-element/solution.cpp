class Solution {
public:
    int firstUniqueEven(vector<int>& nums) {
        unordered_map<int, int> mpp;

        for (int i = 0; i < nums.size(); i++) {
            if ((nums[i] & 1)== 0) {
                mpp[nums[i]]++;
            }
        }

       for(int num : nums){
           if((num &1) == 0 && mpp[num] == 1)
               return num;
       }

        return -1;
    }
};
