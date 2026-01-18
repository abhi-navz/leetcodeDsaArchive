class Solution {
public:
    string removeOuterParentheses(string s) {

        int level = 0;
        string result;

        for (char ch : s) {

            if (ch == '(' && ++level > 1) {
                result.push_back(ch);

            }
            if(ch == ')' && --level >0){
                result.push_back(ch);
            }
        }
        return result;
    }
};
