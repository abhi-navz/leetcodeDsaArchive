    class Solution {
    public:
        bool search(vector<int>& nums, int target) {
            int n = nums.size();
            int st = 0, end = n-1;

            while (st <= end) {

                int mid = st + (end - st) / 2;

                if (nums[mid] == target) {
                    return true;
                }

                // if st , mid and end are eqaul and mid is not equal to my target , i can trim down them out of my search space it's a hurdle in identifying if the arry is left sorted or right sorted correctly. 

                if(nums[st] == nums[mid] && nums[mid] == nums[end]){
                    st++;
                    end--;
                    continue;
                }

                // left sorted
                if (nums[st] <= nums[mid]) {

                    // since it is left sorted so if the target is between st and
                    // mid go left or go right

                    if (nums[st] <= target && target < nums[mid]) {
                        end = mid - 1;
                    } else {
                        st = mid + 1;
                    }

                } else {
                    // right sorted

                    // since it's right sorted if the target is between mid and end
                    // go right or go left

                    if (nums[mid] < target && target <= nums[end]) {
                        st = mid + 1;
                    } else {
                        end = mid - 1;
                    }
                }
            }

            return false;
            
        }
    };
