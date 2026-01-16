class Solution {
public:

    void solve(vector<int>&nums, vector<bool>&used, vector<int>&curr, vector<vector<int>>&result){

        // base case: 
        if(curr.size() == nums.size() ){
            result.push_back(curr);
            return ;
        }

        // choosing 

        for(int i =0; i<nums.size(); i++){

            if(used[i]) continue;

        

            // else mark used and add to current 
            used[i] = true;
            curr.push_back(nums[i]);

            // choose for other indexes 

            solve(nums,used,curr, result);

            // unchoosing 
            curr.pop_back();
            used[i] = false;
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {

        vector<vector<int>>result;
        vector<bool>used(nums.size(),false);

        vector<int>curr;

        solve(nums,used,curr,result);

        return result;
        
    }
};
