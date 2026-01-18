class Solution {
public:
    bool isIsomorphic(string s, string t) {

        if (s.size() != t.size())
            return false;
        int n = s.size();

        unordered_map<char, char> mpp1;
        unordered_map<char, char> mpp2;

        for (int i = 0; i < n; i++) {
            // if s[i] is already mapped check
            if (mpp1.find(s[i]) != mpp1.end()) {
                if (mpp1[s[i]] != t[i])
                    return false;
            }
            
            // becuase of invariant mpp1[x] = y and mpp2[y] = x , we don't need to check both

            // if t[i] is alredy seen check

            else if (mpp2.find(t[i]) != mpp2.end()) {
                if (mpp2[t[i]] != s[i])
                    return false;
            }

            // if none is seen insert
            else {
                mpp1[s[i]] = t[i];
                mpp2[t[i]] = s[i];
            }
        }

        return true;
    }
};
