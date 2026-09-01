class Solution {
public:
    vector<int> minimumTime(int n, vector<vector<int>>& edges, vector<int>& disappear) {
        vector<vector<pair<int,int>>>graph(n);
        for(auto it:edges){
            graph[it[0]].emplace_back(it[1],it[2]);
            graph[it[1]].emplace_back(it[0],it[2]);
        }
        vector<int>dist(n,INT_MAX);
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        // {time,node}
        pq.push({0,0});
        dist[0]=0;

        while(!pq.empty()){
            auto top=pq.top();
            pq.pop();

            int t=top.first;
            int node=top.second;

            if(t>dist[node]) continue;

            for(auto &[u,wt]:graph[node]){
                if(t+wt>=disappear[u]) continue;
                if(dist[u]>t+wt){
                    dist[u]=t+wt;
                    pq.push({t+wt,u});
                }
            }
        }

        for(auto &it:dist) if(it==INT_MAX) it=-1;
        return dist;
    }
};