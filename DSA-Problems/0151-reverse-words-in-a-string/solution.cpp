class Solution {
public:
    string reverseWords(string s) {

        string ans = "";
        int n = s.size();

        ans.reserve(n); // reserving size for the ans;

        // reversing the whole stirng 

        reverse(s.begin(), s.end());

        // reversing every word now

        for(int i =0; i<n; i++){

            string word = "";

            while(i<n && s[i] != ' '){
                word.push_back(s[i]);
                i++;
            }

            reverse(word.begin(), word.end());
            if(!word.empty()){
                if(!ans.empty()){
                    ans.push_back(' ');
                }
                ans.append(word);
            }
            



        }

        return ans;

        

        
    }
};
