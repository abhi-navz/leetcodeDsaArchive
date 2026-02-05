class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {

        string ans = "";

        int n = strs.size();
        int minLen = INT_MAX;

        // calculating min length among all substrings

        for (int i = 0; i < n; i++) {
            int len = strs[i].size();
            minLen = min(minLen, len);
        }

        // taking first string as reference and checking the first character of
        // every string

        string ref = strs[0];
        int j = 0;

        while (j < minLen) {
            bool ok = true;
            for (int i = 1; i < n; i++) {
                if (ref[j] != strs[i][j]) {
                    ok = false;
                    break;
                }
            }

            if (!ok)
                break;
            else {
                ans.push_back(ref[j]);
            }
            j++;
        }

        return ans;
    }
};
