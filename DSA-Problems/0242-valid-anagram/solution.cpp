class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size() != t.size()) return false;

        // making frequency arrays

        int freq[26] = {0};
        

        for ( char ch: s){
            freq[ch-'a']++;
        }
        for ( char ch: t){
            freq[ch-'a']--;
        }

        // comparing the frequencies
        for(int i =0; i<26; i++){

            if(freq[i]!= 0)  return false;

        }

        return true;
        
    }
};
