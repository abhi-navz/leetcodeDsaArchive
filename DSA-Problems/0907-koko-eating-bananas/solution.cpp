class Solution {
public:
    int hours(vector<int>&piles,int speed){
        int hours =0;
        for(int x: piles){
            hours +=  (x+speed-1)/speed; // give us ceil of x/speed;
        }
        return hours;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int low =1;
        int high = 0;
        for (int x : piles) {
            high = max(x, high);
        }

        // answer is between [1, high(11)]

        while(low<high){
            int mid = low+(high-low)/2;
            int k = hours(piles,mid);

            if(k<=h){
                high = mid;
            }else{
                low = mid+1;
            }
        }

        return low;

        
    }
};
