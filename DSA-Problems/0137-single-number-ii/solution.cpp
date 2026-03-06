class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ans = 0;
        for (int bitPos = 0; bitPos < 32; bitPos++) {
            int count = 0;

            for (int i = 0; i < nums.size(); i++) {

                if (nums[i] & (1 << bitPos)) {
                    count++;
                }
            }

            if (count % 3 == 1) {
                ans = ans | (1 << bitPos);
            }
        }
        return ans;
    }
};
