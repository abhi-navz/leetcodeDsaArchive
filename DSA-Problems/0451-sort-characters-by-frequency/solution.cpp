class Solution {
public:
    string frequencySort(string s) {

        string result;
        unordered_map<char, int> mpp;

        for (char ch : s) {
            mpp[ch]++;
        }

        int n = s.size();

        // buckets to stroe char of same freq 'f' in bucket of freq f
        vector<vector<char>> buckets(n + 1);
        // why n+1; coz a charcter can have maximum freq of n so we need buckets
        // of freq 0 to n.

        // map to buckets

        for (auto it : mpp) {

            char ch = it.first;
            int count = it.second;

            buckets[count].push_back(ch);
        }

        // creating result
        
        // traversing the vector from back to get charcter of highesht frequency first
        for (int i = n; i>=0 ; i--) {

            for (char ch : buckets[i]) {
                result.append(i,ch);
            }
        }

        return result;
    }
};
