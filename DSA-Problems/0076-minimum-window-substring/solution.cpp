class Solution {
public:
    string minWindow(string s, string t) {

        int m = s.size();
        int n = t.size();
        if(m<n)return "";

        int stPoint = -1; 
        int minLen = INT_MAX;
        int count =0;

        int l=0;
        vector<int>hash(256,0);

        for(char c: t){
           hash[c]++;
        }


        for(int r =0; r< m; r++){

            if(hash[s[r]] > 0) count++;
            hash[s[r]]--;

            while(count == n){

                if( (r-l+1) < minLen){
                    minLen = r-l+1;
                    stPoint = l;
                }

                hash[s[l]]++;
                if(hash[s[l]] > 0){
                    count--;
                }

                l++;

            }
        }

        if(stPoint == -1) return "";
        return s.substr(stPoint, minLen);





        
    }
};
