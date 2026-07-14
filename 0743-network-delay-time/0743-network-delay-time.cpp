class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int,int>>>graph(n+1);
        for(auto it:times){
            graph[it[0]].emplace_back(it[1],it[2]);
        }
        vector<int>distanceTracer(n+1,INT_MAX);
        priority_queue<vector<int>,vector<vector<int>>,greater<vector<int>>>pq;
        pq.push({0,k});
        distanceTracer[k]=0;

        while(!pq.empty()){
            auto top=pq.top();
            pq.pop();

            int dist=top[0];
            int node=top[1];

            if(dist>distanceTracer[node]) continue;

            for(auto it:graph[node]){
                if(distanceTracer[it.first]>dist+it.second){
                    distanceTracer[it.first]=dist+it.second;
                    pq.push({distanceTracer[it.first],it.first});
                }
            }
        }

        if(count(distanceTracer.begin()+1,distanceTracer.end(),INT_MAX)!=0) return -1;
        return *max_element(distanceTracer.begin()+1,distanceTracer.end());
    }
};