class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size();
        int n2 = nums2.size();

        if(n1 > n2) return findMedianSortedArrays(nums2, nums1);

        int half = (n1 + n2+1 )/ 2;

        // let's say i;ll be taking between 0 and n1 elements from num1

        int low = 0;
        int high = n1;

        double ans;

        while (low <= high) {
            int mid1 = low + (high - low) / 2;
            int mid2 = half - mid1;

            int l1 = INT_MIN;
            int l2 = INT_MIN;

            int r1 = INT_MAX;
            int r2 = INT_MAX;

            if (mid1 - 1 >= 0) {
                l1 = nums1[mid1 - 1];
            }
            if (mid2 - 1 >= 0) {
                l2 = nums2[mid2 - 1];
            }

            if (mid1 <= n1 - 1) {
                r1 = nums1[mid1];
            }
            if (mid2 <= n2 - 1) {
                r2 = nums2[mid2];
            }

            if (l1 <= r2 && l2 <= r1) {

                if((n1+n2)%2 == 0){
                    ans = (max(l1,l2)+min(r1,r2))/2.0;
                }else{
                    ans = max(l1,l2);
                }
                break;
            }else{
                if(l1>r2){
                    high = mid1-1;
                }else if(l2>r1){
                    low = mid1+1;
                }
            }
        }

        return ans;
    }
};
