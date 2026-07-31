class DisjointSetUnion {
private:
    vector<int> rank, parent;

public:
    DisjointSetUnion(int n) {
        rank.resize(n + 1, 0);
        parent.resize(n + 1);

        for (int i = 0; i <= n; i++) {
            parent[i] = i;
        }
    }

    int findUP(int node) {

        if (node == parent[node]) {
            return node;
        }

        return parent[node] = findUP(parent[node]);
    }

    void unionByRank(int u, int v) {
        int pu = findUP(u);
        int pv = findUP(v);

        if (pu == pv)
            return;
        if (rank[pu] < rank[pv]) {
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
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {

        // i have to merge the accounts who have same email. union could be done
        // using dsu, let's gather the accounts belonging to one person as a
        // component.

        int n = accounts.size(); // no of accounts;
        DisjointSetUnion ds(n);

        unordered_map<string, int>
            emailToAccs; // email->account , i;ll store whenever i'll find a new
                         // mail and whenever a mail will reappear i'll simply
                         // merge that account with the first account.

        // merging the accounts.
        for (int i = 0; i < n; i++) {
            for (int j = 1; j < accounts[i].size(); j++) {
                string currEmail = accounts[i][j];
                if (emailToAccs.find(currEmail) != emailToAccs.end()) {
                    ds.unionByRank(i, emailToAccs[currEmail]);
                } else {
                    emailToAccs[currEmail] = i;
                }
            }
        }

        unordered_map< int, set<string> >accToMails;
        for(int i =0; i<n; i++){
            int pu = ds.findUP(i);
            for(int j =1; j<accounts[i].size(); j++){
                accToMails[pu].insert(accounts[i][j]);
            }
        }

        vector<vector<string>>ans;

        for(auto &it : accToMails){
            int accIdx = it.first;
            vector<string>curr;
            curr.push_back(accounts[accIdx][0]);
            for(auto &e : it.second){
                curr.push_back(e);
            }
            ans.push_back(curr);
        }

        return ans;

    }
};