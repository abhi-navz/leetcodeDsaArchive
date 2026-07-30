class Solution {
public:
    string addSpaces(string s, vector<int>& spaces) {
        
        int spcIdx = 0;
        string ans = "";
        ans.reserve(s.size()+spaces.size());
        for(int i =0; i<s.size(); i++){

            if(spcIdx< spaces.size() && spaces[spcIdx] == i){
                ans.push_back(' ');
                spcIdx++;
            }
            ans.push_back(s[i]);
        }
        return ans;
    }
};