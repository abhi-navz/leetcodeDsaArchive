class Solution {
public:
    int getMinDistance(vector<int>& nums, int target, int start) {

        int minDist= INT_MAX;

        for(int i=0;i<nums.size(); i++){
            if(nums[i] == target){
                int dist = abs(i - start);
                minDist = min(minDist,dist);
            }
        }

        return minDist;
        
    }
};
