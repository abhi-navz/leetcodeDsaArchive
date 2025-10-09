class Solution {
public:
    bool isValid(string s) {

        if (s.size() <= 1)
            return false;

        stack<char> st;
        

        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '(' || s[i] == '{' || s[i] == '[') {
                st.push(s[i]);
                
               
            } else {
                if (st.empty()) {
                    return false;
                }
                char top = st.top();
                if (s[i] == ')' && top != '(') {
                    return false;
                } else if (s[i] == '}' && top != '{') {
                    return false;
                } else if (s[i] == ']' && top != '[') {
                    return false;
                }

                st.pop();
            }
        }

        if(!st.empty()){
            return false;
        }

        return true;
    }
}

;
