class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {

        int x = 0;
        for (int i : nums) {
            x ^= i;
        }

        // now x = a^b;  as everything else wouuld have been zero.

        // Find the rightmost set bit in x.
        // This bit represents first position where a and b differ.

        long long diff = (long long)x  &  -(long long)x; 

        // // We divide the numbers into two groups based on this bit.
        // One group has this bit set, the other does not.

        // XOR numbers in the first group.
        // All duplicate numbers cancel out, leaving one unique number.
        int a = 0;
        int b = 0;
        for (int i : nums) {
            if ((i & diff) == 0) {
                // right most bit is not set here
                a = a ^ i;
            } else {
                b = b ^ i;
            }
        }

        return {a, b};
    }
};
