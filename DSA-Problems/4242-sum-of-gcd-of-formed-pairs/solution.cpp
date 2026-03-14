class Solution {
public:
    
    long long gcdSum(vector<int>& nums) {

        int mxi = INT_MIN;
        int n = nums.size();
        vector<int>prefixGcd(n);
        for(int i=0; i< n; i++){
            mxi = max(mxi, nums[i]);
            prefixGcd[i] = gcd(mxi, nums[i]);
        }

        sort(prefixGcd.begin(), prefixGcd.end());

        vector<int>pairGcd;
        for(int i =0; i<n/2; i++){
            pairGcd.push_back(gcd(prefixGcd[i], prefixGcd[n-(i+1)]));
        }

        long long sum =0;
        for(long long x: pairGcd){
            sum += x;
        }

        return sum;
        
    }
};
