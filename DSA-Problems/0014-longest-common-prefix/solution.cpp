class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {

        // fiding the minimum length string
        int minLen = INT_MAX;

        int n = strs.size();
        for (int i = 0; i < n; i++) {
            int len = strs[i].length();
            minLen = min(len, minLen);
        }

        // fiding the common prefix
        string ref = strs[0];
        string result;
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
            result.push_back(ref[j]);

            j++;
        }

        return result;
    }
};
