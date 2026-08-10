typedef long long ll;
class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        vector<vector<pair<int,int>>>graph(n);
        for(auto it:roads){
            graph[it[0]].emplace_back(it[1],it[2]);
            graph[it[1]].emplace_back(it[0],it[2]);
        }
        const int mod=1e9+7;
        vector<ll>dist(n,LLONG_MAX);
        vector<ll>ways(n,0);
        priority_queue<pair<ll,int>,vector<pair<ll,int>>,greater<pair<ll,int>>>pq;
        // {dist,node}
        dist[0]=0;
        ways[0]=1;
        pq.push({0,0});

        while(!pq.empty()){
            auto top=pq.top();
            pq.pop();

            ll d=top.first;
            int node=top.second;

            for(auto it:graph[node]){
                if(dist[it.first]>d+it.second){
                    dist[it.first]=d+it.second;
                    ways[it.first]=ways[node];
                    pq.push({dist[it.first],it.first});
                }else if(dist[it.first]==d+it.second){
                    ways[it.first]=(ways[it.first]+ways[node])%mod;
                }
            }
        }
        return ways[n-1];
    }
};