class Solution {
public:
    string removeOuterParentheses(string s) {

       
        int level =0;
        string ans;

        for(char ch: s ){
            if(ch == '('){
                level++;
                if(level>1){
                    ans.push_back(ch);
                }
            }else{
                level --;
                if(level > 0){
                    ans.push_back(ch);
                }
            }
        }


        return ans;
        
    }
};
