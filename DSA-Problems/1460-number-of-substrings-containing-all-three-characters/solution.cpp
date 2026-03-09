class Solution {
public:
    int numberOfSubstrings(string s) {

        int n = s.size();
        int count = 0;
        vector<int> lastSeen(3, -1); // a(0) = -1, b(1) =-1, c(2) =-1;

        for (int i = 0; i < n; i++) {

            lastSeen[s[i] - 'a'] = i;

            if (lastSeen[0] != -1 && lastSeen[1] != -1 && lastSeen[2] != -1) {
               int minIdx = min(lastSeen[0], lastSeen[1]);
               minIdx = min(minIdx, lastSeen[2]);

               count += 1 + minIdx;
            }
        }

        return count;
    }
};
