class Solution {
public:
    bool canJump(vector<int>& nums) {
        // the idea is to check till which farthest point i can reach from, if i can reach the end of the arry return true;

        // keep track of a fartestpoint reached from any index i, and then check from i+1 only if i+1 is less tha farthestpoint coz it means we can reach i+1, if i+1 is greather than fartestpoint then we can't reach there and return false;

        int n = nums.size();
        int farthestPoint =0;

        for(int i =0; i<n; i++){
            if(i >  farthestPoint) return false;
           

            farthestPoint = max(farthestPoint, i+nums[i]);


        }

        return true;




    }
};
