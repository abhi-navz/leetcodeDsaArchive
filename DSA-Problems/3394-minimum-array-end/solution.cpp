class Solution {
public:
    long long minEnd(int n, int x) {
        
        // to get final anded result as x, we should have x in our array.
        // wherever i have a set bit in x , i can't change em , becuase doing so will not result in x after doing and operation.

        // i'll start with temp = x+1,  and if x& temp == x, then i'm increasing the count and keeping temp as my ans and if temp & x != x then i'm taking or between temp and x, as it'll be the next number which maitains the ones in x and it's places.
        // so temp = temp | x; --> this way i don't have to check all successive numbers

        long long count =1;
        long long ans = x;
        long long temp = x+1;

        while(count<n){
            
            ans = (ans+1)|x;
            count++;
        }

        return ans;
        
    }
};
