class Solution {
public:
    bool isPalindrome(int x) {

        if(x<0) {
            return false;
        }

        int revNum = 0;
        int y = x;
        while(y > 0){
            int lastDigit = y % 10;
            y = y/10;

            if(revNum > INT_MAX/10 || (revNum == INT_MAX && lastDigit>7)){
                return false;
            }

            revNum = revNum * 10 + lastDigit;

        }

        if (x == revNum){
            return true;
        }else{
            return false;
        }

       

        
    }
};
