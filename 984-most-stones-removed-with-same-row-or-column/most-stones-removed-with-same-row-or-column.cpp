class DisjointSetUnion{
    private: 
    vector<int>rank, parent;
    public:
    
    DisjointSetUnion(int n){
        rank.resize(n+1,0);
        parent.resize(n+1);
        
        for(int i =0; i<=n; i++){
            parent[i] = i;
        }
    }
    
    int findUP(int node){
        
        if(node == parent[node]){
            return node;
            
        }
        
        return parent[node] = findUP(parent[node]);
    }
    
    void unionByRank(int u, int v){
        int pu = findUP(u);
        int pv = findUP(v);
        
        if(pu == pv) return ;
        if(rank[pu] < rank[pv]){
            parent[pu] = pv ;
        }else if(rank[pv]<rank[pu]){
            parent[pv] = pu;
        }else{
            parent[pu] = pv;
            rank[pv]++;
        }
    }
    
};
class Solution {
public:
    int removeStones(vector<vector<int>>& stones) {
        
        int maxRow=0, maxCol =0;
        for(const auto &stone : stones){
            maxRow = max(maxRow, stone[0]);
            maxCol = max(maxCol, stone[1]);
        }

        DisjointSetUnion ds(maxRow+ maxCol +1);
        unordered_map<int,int>map;

        for(const auto &stone : stones){
            int row = stone[0];
            int col = stone[1]+maxRow +1;

            ds.unionByRank(row,col);
            map[row]=1;
            map[col] = 1;
        }

        int comps =0;
        for(auto it: map){
            if(ds.findUP(it.first) == it.first) comps++;
        }

        return stones.size()-comps;
    }
};