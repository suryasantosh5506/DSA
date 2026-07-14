class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<int>disTracer(n,INT_MAX);
        vector<vector<pair<int,int>>>graph(n);
        queue<vector<int>>q;

        for(auto it:flights){
            graph[it[0]].emplace_back(it[1],it[2]);
        }

        disTracer[src]=0;
        q.push({0,0,src});
        // {stops,dist,node}

        while(!q.empty()){
            auto top=q.front();
            q.pop();

            int stops=top[0];
            int dist=top[1];
            int node=top[2];

            if(stops>k) continue;

            for(auto it:graph[node]){
                if(disTracer[it.first]>it.second+dist && stops<=k){
                    disTracer[it.first]=it.second+dist;
                    q.push({stops+1,disTracer[it.first],it.first});
                }
            }
        }
        return (disTracer[dst]==INT_MAX)?-1:disTracer[dst];
    }
};