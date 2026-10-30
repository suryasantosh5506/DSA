class Solution {
public:
    int shortestPath(int n, vector<vector<int>>& edges, string labels, int k) {
        vector<vector<pair<int,int>>>graph(n);
        for(auto it:edges){
            graph[it[0]].emplace_back(it[1],it[2]);
        }
        vector<vector<int>>visited(n,vector<int>(k+1,INT_MAX));
        priority_queue<vector<int>,vector<vector<int>>,greater<vector<int>>>pq;
        // {weight,identical characters,node}
        pq.push({0,1,0});
        visited[0][1]=0;

        while(!pq.empty()){
            auto top=pq.top();
            pq.pop();

            int wt=top[0];
            int identical=top[1];
            int node=top[2];

            if(node==n-1) return wt;
            if(identical>k) continue;

            if (wt != visited[node][identical]) continue;

            for(auto it:graph[node]){
                int newCnt=identical;
                if(labels[it.first]==labels[node]) newCnt++;
                else newCnt=1;

                if (newCnt > k) continue;

                if(visited[it.first][newCnt]>wt+it.second){
                    pq.push({wt+it.second,newCnt,it.first});
                    visited[it.first][newCnt]=wt+it.second;
                }
            }
        }
        return -1;
    }
};