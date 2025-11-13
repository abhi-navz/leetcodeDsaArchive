class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {

       
        // fiding provinces using bfs and the matrix
        int n = isConnected.size();
        vector<int>vis(n,0);

        vector<vector<int>>prov;


        for(int i=0;i<n; i++ ){
            if(!vis[i]){
                vector<int>comp;
                queue<int>q;
                vis[i] = 1;
                q.push(i);

                while(!q.empty()){
                    int node = q.front();
                    q.pop();
                    comp.push_back(node);
                    for(int j =0; j<n; j++){
                        if(isConnected[node][j] == 1 && !vis[j]){
                            vis[j] =1;
                            q.push(j);
                        }
                    }
                }

                prov.push_back(comp);
            }
        }

        int noOfProvinces = prov.size();
        return noOfProvinces;


        
    }
};
