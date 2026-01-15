class Solution {
public:
    string removeOccurrences(string s, string part) {

        while(s.find(part) != string::npos){

            int stIdx  = s.find(part);
            int k = part.size();

            s.erase(stIdx, k);

        }

        return s;
        
    }
};
