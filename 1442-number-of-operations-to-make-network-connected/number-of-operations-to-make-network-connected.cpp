class DisjointSetUnion {
	private:
	vector<int>parent, rank;
	public:
	DisjointSetUnion(int n) {
		parent.resize(n + 1);
		rank.resize(n + 1, 0);
		
		for (int i = 0; i <= n; i++) {
			parent[i] = i;
		}
	}
	
	int findUP(int node) {
		if (parent[node] == node) {
			return node;
		}
		return parent[node] = findUP(parent[node]);
	}
	
	void unionByRank(int u, int v) {
		int pu = findUP(u);
		int pv = findUP(v);
		
		// if (pu == pv) return; // same component
		
		if (rank[pu]< rank[pv]) {
			parent[pu] = pv;
		} else if (rank[pv] < rank[pu]) {
			parent[pv] = pu;
		} else {
			parent[pu] = pv;
			rank[pv]++;
		}
		
	}
};

class Solution {
public:
    int makeConnected(int n, vector<vector<int>>& connections) {

        int cables = connections.size();
        if(cables < n-1) return -1;

        DisjointSetUnion ds(n);
        int components = n;

        for(const auto &connection : connections){
            int u = connection[0];
            int v = connection[1];

            if(ds.findUP(u) != ds.findUP(v)){
                ds.unionByRank(u,v);
                components--;
            }
        }

        return components-1;


    }
};