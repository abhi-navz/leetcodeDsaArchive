class Solution {
public:
    string removeKdigits(string num, int k) {
        int n = num.size();

        if (n == k)
            return "0";

        stack<char> st;
        int count = 0;

        for (int i = 0; i < n; i++) {

            while (!st.empty() && st.top() > num[i] && count < k) {
                st.pop();
                count++;
            }
            st.push(num[i]);
        }

        while (count < k && !st.empty()) {
            st.pop();
            count++;
        }
        string ans = "";
        ans.reserve(n);

        while (!st.empty()) {
            ans += st.top();
            st.pop();
        }

        reverse(ans.begin(), ans.end());

        // removing the leading zero but making sure i'm left with one zero in case of all zero
        while (ans.size() > 1 && ans[0] == '0') {
            ans.erase(ans.begin());
        }

        return ans;
    }
};
