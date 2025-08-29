class Solution {
public:

    string cleanString( string s1){
            string result = "";
            for (char c: s1){
                if(isalnum(c)){
                    result += tolower(c);
                }
            }
            return result;
        }

    bool isPalindrome(string s) {

        
        
        string cleaned = cleanString(s);

        for(int i = 0; i<cleaned.length()/2; i++){
            if(cleaned[i] != cleaned[cleaned.length() - i - 1]) return false;
        }
        return true;
    }
};
