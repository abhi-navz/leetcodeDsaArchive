class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        stack<int> st;
        int n = arr.size();
        vector<int> left(n, -1);
        vector<int> right(n, n);

        // buliding array of left indexes

        for (int i = 0; i < n; i++) {
            while (!st.empty() && arr[st.top()] > arr[i]) {
                st.pop();
            }

            if (!st.empty()) {
                left[i] = st.top();
            }

            st.push(i);
        }

        st = stack<int>();

        // building arry of right indexes;

        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && arr[st.top()] >= arr[i]) {
                st.pop();
            }
            if (!st.empty()) {
                right[i] = st.top();
            }

            st.push(i);
        }

        long ans = 0;
        long long mod = 1e9 + 7;

        for (int i = 0; i < n; i++) {
            long long leftDis = i - left[i];
            long long rightDis = right[i] - i;

            long long contribution = (leftDis * rightDis) % mod;
            contribution = (contribution * arr[i]) % mod;

            ans = (ans + contribution) % mod;

            

            
        }

        return ans;
    }
};
