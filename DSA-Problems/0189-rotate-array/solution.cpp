class Solution {
public:
    void rotate(vector<int>& nums, int k) {

        int n = nums.size();
        k = k%n;

        // using the reverse fucniton, revesing the arrays in two different parts
        // and then reversing whole array

        reverse(nums.begin(), nums.begin() + (n-k));
        reverse(nums.begin() + (n-k), nums.begin() + n);
        reverse(nums.begin(), nums.begin() + n);

        
    }
};
