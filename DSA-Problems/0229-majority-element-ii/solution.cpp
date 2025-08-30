class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {

        int n = nums.size();
        unordered_map<int, int> mpp;

        for(int n : nums){
            mpp[n]++;
        }

        // finding the numbers with freq > n/3
        vector<int> ans;

        for(auto el: mpp){
            int element = el.first;
            int freq = el.second;

            if(freq>n/3){
                ans.push_back(element);
            }
        }

        

        
        // sort(ans.begin(), ans.end());

        return ans;
        
    }
};
