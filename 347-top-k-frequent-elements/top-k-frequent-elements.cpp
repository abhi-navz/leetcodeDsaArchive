class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        
        unordered_map<int,int>mp;
        for(int x: nums){
            mp[x]++;
        }

        vector<pair<int,int>>vec;


        for(auto &it: mp){
            int node = it.first;
            int freq = it.second;

            cout<<node<<","<<freq<<endl;
            vec.push_back({freq,node});
        }
        sort(vec.begin(), vec.end(), greater<pair<int,int>>() );
        vector<int>ans;
        for(int i =0; i<k; i++){  
           
           ans.push_back(vec[i].second);
        }

        return ans;

    }
};