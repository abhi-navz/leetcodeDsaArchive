class Solution {
public:
    int solve(vector<int>&prefix, int l, int m){
        
        int n = prefix.size();
        int maxLeftSubSum = 0;
        int res = 0;

        for(int mEnd = l+m-1; mEnd<n; mEnd++){
            int lEnd = mEnd-m;
            int lStPrev = lEnd-l;

            int mBlockSum = prefix[mEnd] - prefix[lEnd];
            int lBlockSum =0;
            if(lStPrev < 0){
                lBlockSum = prefix[lEnd];
            }else{
                lBlockSum = prefix[lEnd] - prefix[lStPrev];
            }

            maxLeftSubSum = max(maxLeftSubSum , lBlockSum);
            res = max(res, maxLeftSubSum+mBlockSum);
        }
        
        return res;
    }
    int maxSumTwoNoOverlap(vector<int>& nums, int firstLen, int secondLen) {
        int n = nums.size();
        vector<int>prefix(n);
        prefix[0] = nums[0];
        for(int i =1; i<n; i++){
            prefix[i] = prefix[i-1]+nums[i];
        }

        return max(solve(prefix,firstLen,secondLen), solve(prefix,secondLen,firstLen));

    }
};