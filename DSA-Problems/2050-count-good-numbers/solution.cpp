class Solution {
public:
    long long MOD = 1e9 + 7;

    long long power(long long base, long long exp) {

        // base case
        if (exp == 0) {
            return 1;
        }
        long long half = power(base, exp / 2) % MOD;

        long long result = (half * half) % MOD;

        if (exp % 2 == 1)
            return (result * base) % MOD;
        else
            return result;
    }
    int countGoodNumbers(long long n) {

        long long evenPositions = (n + 1) / 2;
        long long oddPositions = n / 2;

        // total good numbers would be 5^evenPositons * 4^oddPositions;

        long long even = power(5, evenPositions);
        long long prime = power(4, oddPositions);

        return (even * prime) % MOD;
    }
};
