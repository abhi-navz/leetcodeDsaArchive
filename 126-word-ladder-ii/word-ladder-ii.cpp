class Solution {
public:
    unordered_map<string, vector<string>> parent;
    unordered_map<string, int> level;
    vector<vector<string>> ans;

    void dfs(string word, string beginWord, vector<string>& path) {
        if (word == beginWord) {
            vector<string> temp = path;
            reverse(temp.begin(), temp.end());
            ans.push_back(temp);
            return;
        }

        for (string &par : parent[word]) {
            path.push_back(par);
            dfs(par, beginWord, path);
            path.pop_back();
        }
    }

    vector<vector<string>> findLadders(string beginWord, string endWord,
                                       vector<string>& wordList) {

        unordered_set<string> st(wordList.begin(), wordList.end());

        if (!st.count(endWord))
            return {};

        queue<string> q;
        q.push(beginWord);

        level[beginWord] = 0;

        while (!q.empty()) {
            string word = q.front();
            q.pop();

            int currLevel = level[word];

            string nextWord = word;

            for (int i = 0; i < word.size(); i++) {

                char original = nextWord[i];

                for (char ch = 'a'; ch <= 'z'; ch++) {

                    if (ch == original)
                        continue;

                    nextWord[i] = ch;

                    if (!st.count(nextWord))
                        continue;

                    // First time visiting this word
                    if (!level.count(nextWord)) {
                        level[nextWord] = currLevel + 1;
                        parent[nextWord].push_back(word);
                        q.push(nextWord);
                    }
                    // Another shortest path to this word
                    else if (level[nextWord] == currLevel + 1) {
                        parent[nextWord].push_back(word);
                    }
                }

                nextWord[i] = original;
            }
        }

        if (!level.count(endWord))
            return {};

        vector<string> path;
        path.push_back(endWord);

        dfs(endWord, beginWord, path);

        return ans;
    }
};