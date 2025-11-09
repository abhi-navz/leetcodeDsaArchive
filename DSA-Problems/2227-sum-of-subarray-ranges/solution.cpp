class Solution {
public:
    long long subArrayRanges(vector<int>& nums) {
        int n = nums.size();
        stack<int> st;

        // calculating minSum of all subarrays;

        vector<int> left(n, -1);
        vector<int> right(n, n);

        // calculating leftDist previous smaller indices
        for (int i = 0; i < n; i++) {

            while (!st.empty() && nums[st.top()] > nums[i]) {
                st.pop();
            }
            if (!st.empty()) {
                left[i] = st.top();
            }
            st.push(i);
        }

        st = stack<int>();

        // calcualting Right Dist next Smaller indices

        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && nums[st.top()] >= nums[i]) {
                st.pop();
            }
            if (!st.empty()) {
                right[i] = st.top();
            }
            st.push(i);
        }

        long long minSum = 0;
        for (int i = 0; i < n; i++) {
            long long leftDist = i - left[i];
            long long rightDist = right[i] - i;
            minSum += leftDist * rightDist * nums[i];
        }

        // calculating maxSum of All subarrays;

        st = stack<int>();

        left.assign(n, -1);
        right.assign(n, n);

        // calcuating left distance for previous greater indices;
        for (int i = 0; i < n; i++) {

            while (!st.empty() && nums[st.top()] < nums[i]) {
                st.pop();
            }
            if (!st.empty()) {
                left[i] = st.top();
            }
            st.push(i);
        }

        st = stack<int>();

        // calculating right distance for next greater indices
        for (int i = n - 1; i >= 0; i--) {

            while (!st.empty() && nums[st.top()] <= nums[i]) {
                st.pop();
            }
            if (!st.empty()) {
                right[i] = st.top();
            }
            st.push(i);
        }

        long long maxSum = 0;

        for (int i = 0; i < n; i++) {
            long long leftDist = i - left[i];
            long long rightDist = right[i] - i;
            maxSum += leftDist * rightDist * nums[i];
        }

        return maxSum - minSum;
    }
};
