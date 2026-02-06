class Solution {
public:
    int findMin(vector<int>& nums) {

        int n = nums.size();
        int st = 0;
        int end = n - 1;
        
        while (st < end) {
            int mid = st + (end - st) / 2;

            // right sorted
            // point of rotation is in left part

            if (nums[mid] <= nums[end]) {

                end = mid; // elelments from mid+1 to end are greater than mid but mid could be mininum so we'll shrink search space to [ st, mid]

            } else {
                // left sorted
                // point of rotation is in right part the dip

                st = mid+1;
                
            }
        }

       return nums[st];
    }
};
