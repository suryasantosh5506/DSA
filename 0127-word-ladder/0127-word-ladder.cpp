class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string>st(wordList.begin(),wordList.end());
        queue<pair<string,int>>q;
        st.erase(beginWord);
        q.push({beginWord,1});

        while(!q.empty()){
            auto top=q.front();
            q.pop();

            int steps=top.second;
            string word=top.first;

            if(word==endWord) return steps;

            for(char &ch:word){
                char ori=ch;
                for(char x='a';x<='z';x++){
                    ch=x;
                    if(st.count(word)){
                        q.push({word,steps+1});
                        st.erase(word);
                    }
                }
                ch=ori;
            }
        }
        return 0;
    }
};