class Solution {
public:
    int bitwiseComplement(int n) {
        int  count =0;
        while(n >= (1<< count+1)){
            count++;
        }

        for(int i =0; i<=count; i++){
            n = n ^(1<< i);
        }

        return n;
        
    }
};
