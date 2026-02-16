class Solution {
public:
    void helper(int idx, vector<int>& arr, int target,
                vector<vector<int>>& ans, vector<int>& curr) {

        // base case:
        int n = arr.size();
        if (idx > n - 1) {
             return;
        }
        if (target == 0) {
            ans.push_back(curr);
            return;
        }

        // taking the element when arr[idx]<= target
        if (arr[idx] <= target) {
            curr.push_back(arr[idx]);
            helper(idx, arr, target - arr[idx], ans, curr);
            curr.pop_back(); // restoring the current
        }

        // not taking the element
        helper(idx + 1, arr, target, ans, curr);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> curr;
        int idx = 0;
        int n = candidates.size();

        helper(idx, candidates, target, ans, curr);
        return ans;
    }
};
