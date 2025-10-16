class Solution {
public:

    int fib_helper(int n , vector<int> &memo){
        if(n<2) return n;

        // if the memo vector has already stored the value for n , return it from there directly
        if(memo[n] != -1){
            return memo[n];
        }

        // otherwise calculate it and store it

        memo[n] = fib_helper(n-1, memo) + fib_helper(n-2, memo);
        return memo[n] ;
    }



    int fib(int n) {

        // we'll use a vector for memoization , a vector of size n+1 would be  enough to store all the indexes from 0 to n .This will help in avoiding the fucntion call for lower values multiple times

        vector<int> memo (n+1, -1);

        return fib_helper(n, memo);
    
    }
};
