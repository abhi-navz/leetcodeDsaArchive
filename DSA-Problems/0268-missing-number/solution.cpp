class Solution {
public:
    int missingNumber(vector<int>& nums) {

        // xor approach

        int n = nums.size();
        int xorNums = 0; // xor of array
        int xorAll = 0; // xor of 0 to n;

        for (int i =0; i<=n ; i++){
            xorAll ^= i;

        }
        for (int i =0; i<n ; i++){
            xorNums ^= nums[i];

        }

        return xorAll ^ xorNums;
        
    }
};
