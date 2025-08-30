class Solution {
public:
    int mostFrequentEven(vector<int>& nums) {
        unordered_map<int, int> mpp;
        int maxFreq = 0;
        int ans = -1;

        for(int n: nums){
            if(n%2 == 0){
                mpp[n]++;
                // comparing on the fly 
                if(mpp[n]>maxFreq || (mpp[n] == maxFreq && n<ans)){
                    maxFreq = mpp[n];
                    ans = n;
                }
            }
        }
        return ans;
    }
};
