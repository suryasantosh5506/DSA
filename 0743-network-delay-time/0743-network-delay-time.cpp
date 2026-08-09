class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int,int>>>graph(n+1);
        for(auto it:times){
            graph[it[0]].emplace_back(it[1],it[2]);
        }
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        pq.push({0,k});
        vector<int>dist(n+1,INT_MAX);
        dist[k]=0;

        while(!pq.empty()){
            auto top=pq.top();
            pq.pop();

            int d=top.first;
            int node=top.second;

            if(d>dist[node]) continue;

            for(auto it:graph[node]){
                if(dist[it.first]>d+it.second){
                    dist[it.first]=d+it.second;
                    pq.push({d+it.second,it.first});
                }
            }
        }
        int maxi=*max_element(dist.begin()+1,dist.end());
        return maxi==INT_MAX?-1:maxi;
    }
};