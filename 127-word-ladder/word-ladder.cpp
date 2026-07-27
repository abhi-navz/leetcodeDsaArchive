class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        
        unordered_set<string>st;
        for(string &s : wordList){
            st.insert(s);
        }

        if(st.find(endWord) == st.end())
            return 0;
        queue<string>q;
        int count =0;

        q.push(beginWord);
        st.erase(beginWord);
        
        while(!q.empty()){
            int sz =q.size();
            count++;
            while(sz--){
                string currWord = q.front(); 
                q.pop();
                if(currWord == endWord){
                    return count;
                }
                for(int i =0; i<currWord.size(); i++){
                    string nextWord = currWord;
                    for(char ch = 'a'; ch<='z'; ch++){
                        nextWord[i] = ch;
                        if(st.find(nextWord) != st.end()){
                            q.push(nextWord);
                            st.erase(nextWord);
                        }
                    }                    
                }
            }
            
        } 
        return 0;       
    }
};