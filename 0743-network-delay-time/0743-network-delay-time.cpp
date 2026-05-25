class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int,int>>>graph(n+1);
        for(auto it:times){
            graph[it[0]].emplace_back(it[1],it[2]);
        }
        vector<int>distanceTracer(n+1,1e9);
        distanceTracer[k]=0;

        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        // {time,node};
        pq.push({0,k});

        while(!pq.empty()){
            auto top=pq.top();
            pq.pop();

            int node=top.second;
            int time=top.first;

            for(auto it:graph[node]){
                int v=it.first;
                int d=it.second;

                if(distanceTracer[v]>time+d){
                    distanceTracer[v]=time+d;
                    pq.push({distanceTracer[v],v});
                }
            }
        }
        int ans=*max_element(distanceTracer.begin()+1,distanceTracer.end());
        return (ans==1e9)?-1:ans;
    }
};