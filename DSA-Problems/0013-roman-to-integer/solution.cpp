class Solution {
public:
    int romanToInt(string s) {
        vector<int>val(128);
        val['I'] = 1;
        val['V'] = 5;
        val['X'] = 10;
        val['L'] = 50;
        val['C'] = 100;
        val['D'] = 500;
        val['M'] = 1000;
        

        int n = s.size();
        int ans = val[s[n-1]]; // value of the last character of string
        for(int i=1; i<n; i++){
            if(val[s[i-1]] < val[s[i]]){
                ans -= val[s[i-1]];
            }else{
                ans += val[s[i-1]];
            }
        }


        
       
        return ans;
    }
};
