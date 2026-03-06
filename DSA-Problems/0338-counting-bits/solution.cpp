class Solution {
public:
    vector<int> countBits(int n) {
        if (n == 0) return {0};
        
        vector<int>count(n+1,0);
        count[0] =0;
        count[1] = 1;

        for(int i =2; i<=n; i++){

            if((i & 1) == 0){
                count[i] = count[i/2];
            }else{
                count[i] = count[i/2]+1;
            }
        }

        return count;

        
    }
};
