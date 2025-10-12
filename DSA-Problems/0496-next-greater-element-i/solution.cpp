class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {

        // finding the next greater element for elements of n and storing them in a map

        int n = nums2.size();
        stack<int>st;
        unordered_map<int,int> mpp;
        for(int i = n-1;i>=0; i--){
            while(!st.empty() && nums2[i]>= st.top()){
                st.pop();
            }

            if(st.empty()){
                mpp[nums2[i]] = -1;
            }
            else{
                mpp[nums2[i]] = st.top();
            }

            st.push(nums2[i]);

        }

        vector<int> ans;
        for(int x :nums1){
            ans.push_back(mpp[x]);
        }
        

        return ans;
    }
};
