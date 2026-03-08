class Solution {
public:
    int totalFruit(vector<int>& fruits) {

        int l =0; 
        int n = fruits.size();
        int maxLen =0;
        unordered_map<int,int>mpp;

        for(int r =0; r<n;r++){

            mpp[fruits[r]]++;

            while(mpp.size()> 2){
                mpp[fruits[l]] --;
                if(mpp[fruits[l]] == 0){
                    mpp.erase(fruits[l]);
                }
                l++;
            }

            maxLen = max(maxLen, r-l+1);
        }
        return maxLen;
    }
};
