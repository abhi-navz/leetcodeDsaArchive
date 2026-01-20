class Solution {
public:
    int beautySum(string s) {
        int n = s.size();
        int ans = 0;

        for (int i = 0; i < n; i++) {
           int freq[26]= {0}; // as the string will contian only small english alphabets

            for (int j = i; j < n; j++) {
                freq[s[j] - 'a']++;

                // calculating max and min freq;
                int maxFreq = 0;
                int minFreq = n; // max length of sting
                for (int k=0; k<26; k++) { // const time as the size of freq vector is
                                     // fixed as 26
                    if (freq[k] > 0) {

                        maxFreq = max(maxFreq, freq[k]);
                        minFreq = min(minFreq, freq[k]);
                    }
                }
                ans += (maxFreq - minFreq);
            }
        }
        return ans;
    }
};
