class Solution {
public:
    int ladderLength(string beginWord, string endWord,
                     vector<string>& wordList) {

        unordered_set<string> st;
        // filling the set with wordList
        st.insert(wordList.begin(), wordList.end());

        // if the wordList doesn't contain endWord return 0;
        if (st.count(endWord) == 0)
            return 0;

        queue<string> q;
        q.push(beginWord);
        st.erase(beginWord);

        int length = 0;

        while (!q.empty()) {

            // processing each level and increasing length
            int sz = q.size();
            length++;
            while (sz--) {

                string word = q.front();
                q.pop();
                if (word == endWord)
                    return length;

                for (int i = 0; i < word.length(); i++) {
                    char original = word[i];
                    for (char c = 'a'; c <= 'z'; c++) {
                        if (c == original) continue;
                        word[i] = c; // replacing the ith character of word with c.

                        if (st.count(word)) {
                            st.erase(word); // eraseing the visited word from set to mark it visited
                            q.push(word);
                        }
                    }

                    word[i] = original; // restoring the original word
                }
            }
        }

        return 0;
    }
};
