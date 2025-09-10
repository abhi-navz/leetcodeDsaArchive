class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> arrMap;
        
        

        for(int i =0; i<nums.size();i++){
            
            int x = target - nums[i];

            // checking for the x;
            //Why we CHECK FIRST:
            // If the complement (x) already exists in the map, it means we have seen         another number earlier that together with nums[i] adds up to target.
            // We must check BEFORE inserting nums[i], because:If we insert first, the map will overwrite old indices for duplicate numbers (e.g., nums = [3,3], target=6). Then we would lose the original index and fail to return {0,1}

            if(arrMap.find(x) != arrMap.end()){
               
               return {arrMap[x], i};
            }

            // inserting into the map
            arrMap[nums[i]] = i;    

        }

        

        return {};


        
    }
};
