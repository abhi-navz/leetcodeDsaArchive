class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        // The trick here it is to calcuate the leftextension and rightExtension of a particulary height till it remain minimum, then we can find the reactangle area made by each height using left +right * height;

        int n = heights.size();

        stack<int>st;
        vector<int> left(n,-1);
        vector<int> right(n,n);

        // building leftDis
        for(int i =0; i<n; i++){
            while(!st.empty() && heights[st.top()] > heights[i]){
                st.pop();

            }
            if(!st.empty()){
                left[i] = st.top();
            }
            st.push(i);
        }

        st = stack<int>();
        // building rightDis

        for(int i = n-1; i>=0; i--){
            while(!st.empty() && heights[st.top()] >= heights[i]){
                st.pop();
            }
            if(!st.empty()){
                right[i] = st.top();
            }
            st.push(i);
        }

        int maxRec =0;

        for(int i =0; i<n; i++){
            int width = right[i] - left[i] - 1;
            int currRec = width* heights[i];
            maxRec = max(maxRec, currRec);

        }

        return maxRec;
        
    }
};
