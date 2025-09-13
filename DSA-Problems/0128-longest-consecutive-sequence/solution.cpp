class Solution {
public:


    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        if(n == 0) return 0;
        int longest = 1;

       // making set out of the array nums;
        unordered_set<int> st; 
        for(int i : nums){
            st.insert(i);
        }

        // iterate through set, if the predecessor of the element doesn't exist in the set, pick the elemeent with count 1 and look for sucessors in the set, keep track of current count and longest streak

        for(auto it:st){
            if(st.find(it-1) == st.end()){
                int count = 1;
                int x = it;

                // chekcing for continous elements;

                while(st.find(x+1) != st.end()){
                    x = x+1;
                    count++;
                }

                longest = max(longest, count);
            }
        }

        return longest;
        
    }
};
