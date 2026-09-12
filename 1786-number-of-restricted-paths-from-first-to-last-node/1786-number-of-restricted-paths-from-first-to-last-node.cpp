typedef long long ll;
class Solution {
public:

    int n;
    const int mod=1e9+7;
    vector<vector<pair<int,int>>>graph;
    vector<vector<pair<int,int>>>newgraph;
    vector<int>dist;
    vector<int>paths;
    vector<int>newdist;

    void dijsktras(){
        dist.resize(n+1,INT_MAX);
        priority_queue<vector<int>,vector<vector<int>>,greater<vector<int>>>pq;
        pq.push({0,n});
        dist[n]=0;

        while(!pq.empty()){
            auto top=pq.top();
            pq.pop();

            int d=top[0];
            int node=top[1];

            if(dist[node]<d) continue;

            for(auto [u,wt]:graph[node]){
                if(dist[u]>d+wt){
                    dist[u]=d+wt;
                    pq.push({d+wt,u});
                }
            }
        }
    }

    int count(int node){
        if(node==n) return 1;
        if(paths[node]!=-1) return paths[node];

        int ans=0;
        for(auto [u,wt]:newgraph[node]){
            if(dist[node]>dist[u]){
                ans=(ans+count(u))%mod;
            }
        }
        return paths[node]=ans;
    }

    int countRestrictedPaths(int n, vector<vector<int>>& edges) {
        this->n=n;
        graph.resize(n+1);
        for(auto it:edges){
            graph[it[0]].emplace_back(it[1],it[2]);
            graph[it[1]].emplace_back(it[0],it[2]);
        }
        dijsktras();
        vector<vector<int>>newedges;
        for(auto it:edges){
            int u=it[0],v=it[1];
            if(dist[u]>dist[v]){
                newedges.emplace_back(it);
            }else if(dist[v]>dist[u]){
                newedges.push_back({it[1],it[0],it[2]});
            }
        }
        newgraph.resize(n+1);
        for(auto it:newedges){
            newgraph[it[0]].emplace_back(it[1],it[2]);
        }
        paths.resize(n+1,-1);
        return count(1);
    }
};