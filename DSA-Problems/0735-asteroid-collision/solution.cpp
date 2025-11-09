class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        int n = asteroids.size();

        vector<int> ans;
        stack<int> st;

        for (int i = 0; i < n; i++) {
            int curr = asteroids[i];
            bool destroyed = false;

            if (st.empty() || curr > 0 || st.top() < 0) {
                st.push(curr);
                continue;
            }

            // now the curr passing from here will be negative and top is fs +ve;

            while (!st.empty() && st.top() > 0) {

                int top = st.top();

                if (top < -curr) {
                    st.pop(); // top dies, and the while loop will run agian to check for next top as the curr won.
                } else if (top == -curr) {
                    st.pop(); // both dies in this case
                    destroyed = true;
                    break; // will break the while loop as curr didn't win here.
                } else {
                    // top bigger;
                    destroyed = true;
                    break; // breaking out of loop as curr lost.
                }
            }

            if (!destroyed) {
                st.push(curr);
            }
        }

        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }

        reverse(ans.begin(), ans.end());
        return ans;
    }
};
