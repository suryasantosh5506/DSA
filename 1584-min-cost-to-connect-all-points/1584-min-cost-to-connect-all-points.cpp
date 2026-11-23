class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n=points.size();
        vector<vector<pair<int,int>>>graph(n);
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(j==i) continue;
                graph[i].emplace_back(j,abs(points[i][0]-points[j][0])+abs(points[i][1]-points[j][1]));
            }
        }
        vector<int>visited(n,0);
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        pq.push({0,0});
        int sum=0;
        while(!pq.empty()){
            auto [wt,node]=pq.top();
            pq.pop();

            if(visited[node]) continue;
            sum+=wt;
            visited[node]=1;

            for(auto [v,d]:graph[node]){
                if(!visited[v]) pq.push({d,v});
            }
        }
        return sum;
    }
};