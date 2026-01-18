class Solution {
public:
    string reverseWords(string s) {

        int n = s.size();
        reverse(s.begin(), s.end());

        int idx = 0;
        for (int i = 0; i < n; i++) {

            if (s[i] == ' ')
                continue;

            if (idx != 0)
                s[idx++] = ' ';

            int j = i; 
            while(j<n && s[j]!= ' ')  {
                s[idx++] = s[j++];
            }

            // reverse the word
            reverse(s.begin()+idx-(j-i), s.begin()+idx); 
            // moving i at j 
            i = j-1; // as i will be incremented by the for loop by 1
        }

        s.resize(idx); // to eliminate the garabage in the end

        return s;
    }
};
