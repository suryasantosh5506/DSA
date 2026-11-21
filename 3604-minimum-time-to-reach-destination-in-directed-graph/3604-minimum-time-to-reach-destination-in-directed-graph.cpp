class Solution {
public:
    int minTime(int n, vector<vector<int>>& edges) {
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        // {time,node}
        vector<int>dist(n,INT_MAX);
        // {node:time}
        vector<vector<vector<int>>>tree(n);
        for(auto it:edges){
            tree[it[0]].push_back({it[1],it[2],it[3]});
        }
        pq.push({0,0});
        dist[0]=0;

        while(!pq.empty()){
            auto [t,node]=pq.top();
            pq.pop();

            if(node==n-1) return t;
            
            if(dist[node]<t) continue;

            for(auto it:tree[node]){
                if(t>it[2]) continue;
                int time=max(t,it[1])+1;

                if(time<dist[it[0]]){
                    dist[it[0]]=time;
                    pq.push({time,it[0]});
                }
            }
        }
        return -1;
    }
};