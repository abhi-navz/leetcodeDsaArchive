class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {

        int count =0;
        long long sum = 0;
        unordered_map<long long , int> preSumMap;
        preSumMap[0] =1; // base case in case we got k at first. we'll get remaining as zero, so by this we use our preSumMap to know ki yeah the rem is present in hashmap. k-k =0

        for(int i =0; i<nums.size(); i++){
            sum += nums[i];

            long long rem = sum -k;

            if(preSumMap.find(rem) != preSumMap.end()){
                count += preSumMap[rem]; // add all occurences.
            }

            preSumMap[sum]++;

        }

        return count;
        
    }
};
