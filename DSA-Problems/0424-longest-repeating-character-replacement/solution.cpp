class Solution {
public:
    int characterReplacement(string s, int k) {

        int n = s.size();
        int maxLen =0;
        int maxFreq = 0;
        int l =0;

        vector<int>freq(26,0); // 26 upper case characters

        for(int r =0; r<n; r++){
            freq[s[r]-'A']++;
            maxFreq = max(maxFreq, freq[s[r] -'A']);

            // checking the valid window conditon : windowSize - maxFreq <= k ---> valid

            while(((r-l+1) - maxFreq ) > k){
                
                freq[s[l] -'A']--;
                // maxFreq = max( maxFreq, freq[s[r] -'A'] ); thsi line is redundant here tho, coz as r moves the winoow will get valid and correct itslef, by decreasing maxFreq here i'll only get smaller valid windows that previus which is not required.
                l++;
                
               

            }

            maxLen = max( maxLen, r-l+1);

        }

        return maxLen;

    }
};
