class Solution {
public:
    void expand(int l, int r, int &start, int &bestLen, const string &s) {

        int n = s.size();

        // expand
        while(l>=0 && r<n && s[l] == s[r]){
            int len = r-l+1;
            if(len >bestLen){
                bestLen = len;
                start = l;
            }
            l--;
            r++;
        }
    }
    string longestPalindrome(string s) {
        
        int bestLen =0, start =0;

        for (int i = 0; i < s.size(); i++) {

            // odd center (l = i, r =i)
            expand(i, i, start, bestLen, s);

            // even center (l =i, r = i+1)
            expand(i, i + 1,start, bestLen, s);
        }
        
        return s.substr(start,bestLen);
    }
};
