class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {

        // for a array of n elements, we'll have 2^n subsets
        // Each subset can be represented using a binary number from 0 to (1<<n)-1.

        /* Each bit in the mask represents whether we include that element or not.

        bit = 1 → include element
        bit = 0 → skip element

        */

        /*  We iterate through all masks.
         For each mask we check all bit positions from 0 to n-1.

         To check if a bit is set:

         mask & (1<<i)
         If the result is non-zero, we include nums[i] in the current subset.

        */
        vector<vector<int>>ans;
        int n = nums.size();
        int subsets = 1<<n;

        for(int mask = 0; mask<subsets; mask++){

            vector<int>sub;
            for(int i =0; i<n; i++){
                
                if(mask &(1 << i)){
                    sub.push_back(nums[i]);
                }
            }

            ans.push_back(sub);

        }
        return ans;

        
        
    }
};
