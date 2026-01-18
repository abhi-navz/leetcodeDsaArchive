class Solution {
public:
    string largestOddNumber(string num) {

        int n = num.size();
        int j = n - 1;

        while (j >= 0) {
            int digit = num[j] - '0';
            if (digit % 2 == 1) {
                break;
            }

            j--;
        }

        if (j == -1) return "";

        return num.substr(0,j+1);
    }
};
