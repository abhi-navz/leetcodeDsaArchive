class Solution {
public:
    void helper(int idx, int k, int target,vector<int>&arr,vector<vector<int>>&ans,vector<int>&ds){

        // base case 
        if(ds.size() == k){
            if(target == 0){
                ans.push_back(ds);
            }
            return;
        }
        if(target == 0) return;


        if(idx == 9){
            return;
        }
        if(arr[idx]>target ){
            return;
        }

        // take 
        ds.push_back(arr[idx]);
        helper(idx+1,k,target-arr[idx],arr,ans,ds);

        // skip
        ds.pop_back();
        helper(idx+1,k,target,arr,ans,ds);

    }

    vector<vector<int>> combinationSum3(int k, int n) {

        vector<int>arr = {1,2,3,4,5,6,7,8,9};

        vector<vector<int>>ans;
        vector<int>ds;

        helper(0,k,n,arr,ans,ds);

        return ans;
        
    }
};
