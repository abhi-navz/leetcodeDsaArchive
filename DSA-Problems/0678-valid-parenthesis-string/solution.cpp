class Solution {
public:
    bool checkValidString(string s) {

        int n = s.size();
        int low =0;
        int high =0; // maintaining a possible range of count

        for(int i=0; i<n; i++){
            if(s[i] == '('){
                low++;
                high++;
            }
            else if(s[i] == ')'){
                low--;
                high--;
                if(high<0)return false;
                if(low<0) low =0;
            }else{
                low--;
                high++;
                if(low< 0) low =0;

            
            }
        }

        return (low == 0);
        
    }
};
