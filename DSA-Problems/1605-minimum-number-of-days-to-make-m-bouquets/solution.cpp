class Solution {
public:
    bool valid(vector<int>& bloomDay, int m, int k, int mid) {
        int n = bloomDay.size();
        int count = 0;
        int adj = 0;

        for (int i = 0; i < n; i++) {
            if (bloomDay[i] <= mid) {
                {
                    adj++;
                }

            } else {
                adj = 0;
            }

            if (adj == k) {
                count++;
                adj = 0;
                if (count == m)
                    return true;
            }
        }

        return false;
    }
    int minDays(vector<int>& bloomDay, int m, int k) {

        int n = bloomDay.size();
        long long totalFlowersNeeded = (long long)m*k;
        if (totalFlowersNeeded > n)
            return -1;

        int low = INT_MAX, high = 1; // minimum days would be 1 at least
        for (int day : bloomDay) {
            low = min(low, day);
            high = max(high, day);
        }

        // my answer will be in the range low and high

        while(low<=high){
            int mid = low+(high-low)/2;

            if(valid(bloomDay,m,k, mid) == true){
                // go left and check for smaller no of days
                
                high = mid-1;
            }else{
                // go right 
                low = mid+1;
            }
        }

        return low;


    }
};
