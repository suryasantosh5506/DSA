class Solution {
public:

    vector<vector<int>>tree;
    vector<int>sizearr;
    vector<int>visited;

    int solution(int node){
        int ans=1;
        visited[node]=1;
        for(auto it:tree[node]){
            if(!visited[it]) ans+=solution(it);
        }
        return sizearr[node]=ans;
    }

    int count(int node){
        visited[node]=1;
        int size=-1;
        bool ok=true;
        int ans=0;
        for(auto it:tree[node]){
            if(visited[it]) continue;

            if(size==-1){
                size=sizearr[it];
            }else{
                if(size!=sizearr[it]) ok=false;
            }
            ans+=count(it);
        }
        if(ok) ans++;
        return ans;
    }

    int countGoodNodes(vector<vector<int>>& edges) {
        int n=edges.size();
        tree.resize(n+1);
        sizearr.resize(n+1,0);
        visited.resize(n+1,0);

        for(auto it:edges){
            tree[it[0]].emplace_back(it[1]);
            tree[it[1]].emplace_back(it[0]);
        }

        solution(0);
        visited.assign(n+1,0);
        return count(0);
    }
};