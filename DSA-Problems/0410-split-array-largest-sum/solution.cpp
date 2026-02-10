class Solution {
public:
    int countSubset(vector<int>&nums,int capacity){

        int count =1;
        int currSum =0;

        for(int el: nums){
            if(currSum+el <= capacity){
                currSum += el;
            }else{
                count++;
                currSum = el;
            }
        }

        return count;

    }

    int splitArray(vector<int>& nums, int k) {

        int low =0,high = 0;
        for(int x: nums){
            low = max(low,x);
            high+= x;
        }

        while(low<=high){
            int mid = low+(high-low)/2;

            int subsetCount = countSubset(nums,mid);
            if(subsetCount<=k){
                high = mid-1;
            }else{
                low = mid+1;
            }
        }
        return low;
    }
};
