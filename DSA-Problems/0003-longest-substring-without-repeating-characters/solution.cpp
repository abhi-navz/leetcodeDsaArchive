class Solution {
public:
    int lengthOfLongestSubstring(string s) {

        int n = s.size();

        int l = 0, r = 0;
      
        int maxLen = 0;
        vector<int>last(256,-1);

        while (r < n) {
            if(last[s[r]] >=l){
                l = last[s[r]] +1;
            }

            last[s[r]] = r;
            maxLen = max(maxLen, r-l+1);
           
            r++;
        }
        return maxLen;
    }
};
