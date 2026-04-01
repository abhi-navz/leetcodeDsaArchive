class Solution {
public:
    int minimumDifference(vector<int>& nums) {

        int n = nums.size();
        int half = n / 2;

        vector<int> left(nums.begin(), nums.begin() + half);
        vector<int> right(nums.begin() + half, nums.end());

        int total = accumulate(nums.begin(), nums.end(), 0);

        vector<vector<int>> leftSums(half + 1);
        vector<vector<int>> rightSums(half + 1);

        // generate subset sums for left half
        for(int mask = 0; mask < (1 << half); mask++) {
            int sum = 0, bits = 0;
            for(int i = 0; i < half; i++) {
                if(mask & (1 << i)) {
                    sum += left[i];
                    bits++;
                }
            }
            leftSums[bits].push_back(sum);
        }

        // generate subset sums for right half
        for(int mask = 0; mask < (1 << half); mask++) {
            int sum = 0, bits = 0;
            for(int i = 0; i < half; i++) {
                if(mask & (1 << i)) {
                    sum += right[i];
                    bits++;
                }
            }
            rightSums[bits].push_back(sum);
        }

        for(int i = 0; i <= half; i++)
            sort(rightSums[i].begin(), rightSums[i].end());

        int ans = INT_MAX;

        for(int k = 0; k <= half; k++) {

            for(int s1 : leftSums[k]) {

                int target = total / 2 - s1;

                auto &vec = rightSums[half - k];

                auto it = lower_bound(vec.begin(), vec.end(), target);

                if(it != vec.end()) {
                    int s2 = *it;
                    int sum1 = s1 + s2;
                    ans = min(ans, abs(total - 2 * sum1));
                }

                if(it != vec.begin()) {
                    --it;
                    int s2 = *it;
                    int sum1 = s1 + s2;
                    ans = min(ans, abs(total - 2 * sum1));
                }
            }
        }

        return ans;
    }
};
