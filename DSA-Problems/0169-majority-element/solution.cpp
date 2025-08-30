class Solution {
public:
    int majorityElement(vector<int>& nums) {

        unordered_map<int, int> mpp;
        for(int n: nums){
            mpp[n]++;
        }

        int maxFreq = 0;
        int majEl = 0;

        // traversing through the map or hash table
        for(auto el: mpp){
            int element = el.first;
            int count = el.second;

            if(count>maxFreq){
                maxFreq = count;
                majEl = element;
            }
           
        }
        return majEl;
    }
        
        
    
};
