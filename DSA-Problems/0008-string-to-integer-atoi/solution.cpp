class Solution {
public:
    int helper(int idx, int size, int sign, int ans, string &s ){

        // base case 
        if(idx>size || !isdigit(s[idx])){
            return sign*ans;
        }

        int digit = s[idx] - '0';

        // overflow check 
        if(ans> (INT_MAX-digit)/10){
            return (sign == 1)? INT_MAX: INT_MIN;
        }
        ans = ans*10+digit;

        return helper(idx+1,size,sign,ans,s);


    }
    int myAtoi(string s) {
        int n = s.size();
        if(n == 0) return 0;
        int i =0;

        // skip spaces

        while(i<n && s[i] == ' '){
            i++;
        }

        // pick the sign 
        int sign = 1;
        if(i<n && (s[i] == '+' || s[i] == '-')){
            if(s[i] == '-') sign = -1;
            i++;
        } 
        // the above loop will check till it get's one sign element after that it'll exit the loop

        
        int ans =0;
        // start recursion

        return helper(i,n,sign,ans,s);


        
    }
};
