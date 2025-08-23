class Solution {
public:
    int maximumCount(vector<int>& nums) {

        int n = nums.size();
        

        // calcualting no of negative number by finding first index where nums[il >=0; that is first non negative number
        int st =0;
        int end = n-1;
        int firstNonNeg = n; // in case all numbers are negative.

        while(st<=end){
            int mid =  st + (end-st)/2;

            if(nums[mid] >=0){
                firstNonNeg = mid; // a positive number is found.
                end = mid-1;
            }
            else{
                st = mid+1; // a negative number is found 
            }
        }
        

        // calcualting no of positive number by finding  last index where nums[il <=0; that is last non positve number.

        st =0;
        end = n-1;
        int lastNonPos = -1 ;// in case all are positive

        while(st<=end){

            int mid = st+ (end-st)/2;

            if(nums[mid] <=0){
                lastNonPos = mid; // a non positive no is find
                st = mid+1; // to check if there are more non postive numbers ahead

            }
            else{
                end = mid -1;
            }
        }

         int negCount = firstNonNeg;              // all before first >= 0
        int posCount = n - (lastNonPos + 1);     // all after last <= 0

        return max(negCount, posCount);


    }
};
