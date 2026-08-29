class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        unordered_set<string>st(deadends.begin(),deadends.end());
        unordered_set<string>visited;
        if (st.count("0000")) return -1;
        queue<pair<string,int>>q;
        q.push({"0000",0});
        visited.insert("0000");

        while(!q.empty()){
            auto top=q.front();
            q.pop();

            string key=top.first;
            int moves=top.second;

            if(key==target) return moves;

            for(int i=0;i<=3;i++){
                char ch=key[i];
                int next=((ch-'0')+1)%10;
                int prev=((ch-'0')+9)%10;

                key[i]=next+'0';
                if(!st.count(key) && !visited.count(key)){
                    q.push({key,moves+1});
                    visited.insert(key);
                }
                key[i]=prev+'0';
                if(!st.count(key) && !visited.count(key)){
                    q.push({key,moves+1});
                    visited.insert(key);
                }
                key[i]=ch;
            }
        }
        return -1;
    }
};