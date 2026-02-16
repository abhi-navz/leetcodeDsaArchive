class Solution {
public:
    void helper(int idx, vector<int>& arr, vector<vector<int>>& ans,
                vector<int>& ds) {

        int n = arr.size();

        // base case

        ans.push_back(ds);

        for (int i = idx; i < n; i++) {
            if (i > idx && arr[i] == arr[i - 1])
                continue;
            ds.push_back(arr[i]);
            helper(i + 1, arr, ans, ds);
            ds.pop_back();
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {

        vector<vector<int>> ans;
        vector<int> ds;

        // sort the array

        sort(nums.begin(), nums.end());

        helper(0, nums, ans, ds);
        return ans;
    }
};
