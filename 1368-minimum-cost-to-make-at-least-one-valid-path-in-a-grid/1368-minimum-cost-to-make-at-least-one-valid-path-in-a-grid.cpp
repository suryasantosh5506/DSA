class Solution {
public:

    int n,m;

    bool isValid(int i,int j){
        return (i>=0 && i<n) && (j>=0 && j<m);
    }

    int minCost(vector<vector<int>>& grid) {
        n=grid.size();
        m=grid[0].size();
        vector<vector<pair<int,int>>>graph(n*m);
        vector<int>distTracer(n*m,INT_MAX);
        unordered_map<int,vector<int>>mpp={
            {1,{0,1}},
            {2,{0,-1}},
            {3,{1,0}},
            {4,{-1,0}}
        };

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                for(auto it:mpp){
                    int nr=i+it.second[0];
                    int nc=j+it.second[1];
                    int cost=(grid[i][j]==it.first)?0:1;
                    if(isValid(nr,nc)) graph[i*m+j].emplace_back(nr*m+nc,cost);
                }
            }
        }

        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        pq.push({0,0});
        distTracer[0]=0;

        while(!pq.empty()){
            auto top=pq.top();
            pq.pop();

            int i=top.second/m;
            int j=top.second%m;
            int dist=top.first;

            if(i==n-1 && j==m-1) return dist;
            if(dist>distTracer[top.second]) continue;

            for(auto it:graph[top.second]){
                if(distTracer[it.first]>dist+it.second){
                    pq.push({dist+it.second,it.first});
                    distTracer[it.first]=dist+it.second;
                }
            }
        }
        return -1;
    }
};