class Solution {
public:
    int divide(int dividend, int divisor) {

        // edge case
        if (dividend == INT_MIN && divisor == -1) {
            return INT_MAX;
        }

        // determine sign
        bool sign = true;
        if (dividend < 0 && divisor >= 0)
            sign = false;
        if (dividend >= 0 && divisor < 0)
            sign = false;

       long long dvd = dividend;
       long long dvs = divisor;

        if (dvd < 0) dvd = -dvd;
        if (dvs < 0) dvs = -dvs;

        long long result = 0;

        while (dvd >= dvs) {
            int count = 0;
            while (dvd >= (dvs << (count + 1))) {
                count++;
            }

            result += 1 << count;
            
            dvd = dvd - (dvs << count);
        }

        if(!sign){
            return -result;
        }

        return result;
    }
};
