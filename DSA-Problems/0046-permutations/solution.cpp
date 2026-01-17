class Solution {

public:
    void solve(vector<int>& nums, vector<vector<int>>& result, int idx, int n) {

        if (idx == n) {
           
            result.push_back(nums);
            return;
        }

        for (int i = idx; i < n; i++) {

            // swap
            

                swap(nums[idx], nums[i]);
            

            // go lower level
            solve(nums, result, idx + 1, n);

            // backtrack
           

                swap(nums[idx], nums[i]);
            
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {

        vector<vector<int>> result;
        int n = nums.size();
        int idx = 0;

        solve(nums, result, idx, n);
        return result;
    }
};
