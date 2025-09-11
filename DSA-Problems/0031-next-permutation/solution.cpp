class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        // there's stl library next_permutation , which we can use to return the answer.
        // next_permutation(nums.begin(), nums.end());

        // implementing the STL itself

        int n = nums.size();
        int index = -1;

        // finding the larger prefix match, by finding the break point index

        for(int i = n-2; i>=0; i--){
            if(nums[i] <nums[i+1]){
                index = i;
                break;

            }
            
        }

        if(index == -1) // the array in decreassing order and at the max permuatation, we'll simply reverse the array to get the first smallest permutaion
        {
            reverse(nums.begin(), nums.end());
            return;

        }

        // Step 02: finding el larger than arr[index], but the samllest larger one so we can keep it close

        for(int i = n-1; i> index; i--){
            if(nums[i]>nums[index]){
                swap(nums[i], nums[index]);
                break;
            }
        }

        // step 03: placing the remaining in the sorted order by reversing the rest 

        reverse(nums.begin()+index+1, nums.end());
        
        
    }
};
