class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n);

        int posIndex = 0, negIndex = 1;

        for (int x : nums) {
            if (x >= 0) {
                ans[posIndex] = x;
                posIndex += 2;
            } else {
                ans[negIndex] = x;
                negIndex += 2;
            }
        }

        return ans;
        
    }
};
