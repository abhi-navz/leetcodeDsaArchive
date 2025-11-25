class Solution {
public:
    vector<bool> prefixesDivBy5(vector<int>& nums) {
        int temp=0;
        vector<bool> ans;

        for(auto it:nums){
            temp=temp<<1;
            temp=temp | it;

            temp=temp%5;

            if(temp==0) ans.push_back(true);
            else ans.push_back(false);
        }

        return ans;
    }
};
