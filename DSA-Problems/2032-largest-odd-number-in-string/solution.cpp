class Solution {
public:
    string largestOddNumber(string num) {

        int n = num.size();
        int length = 0;
        for(int j=n-1; j>=0; j--){
            int digit = num[j] - '0';

            if(digit %2 != 0){
                length = j+1;
                break;
            }
        }
        
        if(length == 0) return "";
        return num.substr(0,length);
    }
};
