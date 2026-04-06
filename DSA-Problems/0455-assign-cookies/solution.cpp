class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {

        int i = 0, j = 0;
        int m = g.size();
        int n = s.size();

        sort(s.begin(), s.end());
        sort(g.begin(), g.end());
        int count = 0;

        while (i < m && j < n) {
            if (g[i] <= s[j]) i++;
            j++;
        }

        return i;
    }
};
