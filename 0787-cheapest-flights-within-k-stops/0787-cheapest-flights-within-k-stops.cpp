class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<int>dist(n,INT_MAX);
        vector<vector<pair<int,int>>>graph(n);

        for(auto it:flights){
            graph[it[0]].emplace_back(it[1],it[2]);
        }

        priority_queue<vector<int>,vector<vector<int>>,greater<vector<int>>>pq;
        pq.push({0,0,src});
        // {stops,dist,src}
        dist[src]=0;

        while(!pq.empty()){
            auto top=pq.top();
            pq.pop();

            int stops=top[0];
            int d=top[1];
            int node=top[2];
            if(stops>k) continue;

            for(auto it:graph[node]){
                if(dist[it.first]>d+it.second && stops<=k){
                    dist[it.first]=d+it.second;
                    pq.push({stops+1,d+it.second,it.first});
                }
            }
        }
        return dist[dst]==INT_MAX?-1:dist[dst];
    }
};