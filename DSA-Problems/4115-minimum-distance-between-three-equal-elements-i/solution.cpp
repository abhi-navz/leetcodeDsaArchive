class Solution {
public:
    int minimumDistance(vector<int>& nums) {
        /*
            since k>j>i
            |j-i|+|k-j|+|k-i| = j -i + k - j + k -i = 2(k-i), the answer only
         depends on k and i, index of first occ and idex of last occurence we
         can keep a hashmap will will trace the indexes of occurene of an
         element, and when a element have three occurence, we'll return the ans
         using first and the last idx.

         */

        int n = nums.size();
        int ans = INT_MAX;
        unordered_map<int, vector<int>> mpp;

        for(int i =0;i<n; i++){
            mpp[nums[i]].push_back(i);

            if(mpp[nums[i]].size() >= 3){
                
                int sz = mpp[nums[i]].size();
                // mean the vector have 3 indexes in it, the first one at sz-3, and the third
                // one at sz-1
                int i1 = mpp[nums[i]][sz-3];
                int i3 = mpp[nums[i]][sz-1]; 

                ans = min(ans, 2*(i3-i1));
            }
        }

        return (ans == INT_MAX)? -1 : ans;

    }
};
