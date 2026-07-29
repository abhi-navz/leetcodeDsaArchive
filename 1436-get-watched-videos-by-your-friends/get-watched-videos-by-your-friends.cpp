class Solution {
public:
    vector<string> watchedVideosByFriends(vector<vector<string>>& watchedVideos, vector<vector<int>>& friends, int id, int level) {
        int n = friends.size();
        int lvl = -1;
        queue<int>q;
        vector<int>vis(n,0);

        q.push(id);
        vis[id] = 1;
        vector<int>people;
        while(!q.empty() && lvl < level){
            lvl++;
            int sz = q.size();
            while(sz--){
                int node = q.front(); q.pop();
                if(lvl == level){
                    people.push_back(node);
                }
                for(int nxt : friends[node]){
                    if(!vis[nxt]){
                        q.push(nxt);
                        vis[nxt] = 1;
                    }
                }
            }
        }

        unordered_map<string, int>mp;

        for(int x : people){
            for(string &s : watchedVideos[x] ){
                mp[s]++;
            }
        }

        vector<pair<string, int>>v(mp.begin(),mp.end());

        sort(v.begin(),v.end(),[](const auto &a, const auto &b){
            if(a.second == b.second){
                return a.first<b.first; // lexicographical order
            }
            return a.second < b.second; // lower frequency first
        });

        vector<string>ans;
        for(auto &[word,count] : v){
            ans.push_back(word);
        }
        return ans;
    }
};