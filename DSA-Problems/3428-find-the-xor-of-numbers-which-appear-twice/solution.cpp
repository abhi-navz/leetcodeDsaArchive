class Solution {
public:
    int duplicateNumbersXOR(vector<int>& nums) {

       unordered_set<int>seen;
        int ans =0;
        for(int x: nums){
            
            if(seen.count(x)){
                ans ^= x;
            }else{
                seen.insert(x);
            }

        }
        return ans;
        
    }
};
