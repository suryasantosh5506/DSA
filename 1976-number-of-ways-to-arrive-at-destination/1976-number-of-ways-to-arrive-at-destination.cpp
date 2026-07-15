typedef long long ll;
class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        const int mod=1e9+7;
        vector<vector<pair<ll,ll>>>graph(n);
        vector<ll>distanceTracer(n,LLONG_MAX);
        vector<ll>ways(n,0);
        priority_queue<vector<ll>,vector<vector<ll>>,greater<vector<ll>>>pq;

        for(auto it:roads){
            graph[it[0]].emplace_back(it[1],it[2]);
            graph[it[1]].emplace_back(it[0],it[2]);
        }

        distanceTracer[0]=0;
        ways[0]=1;
        pq.push({0,0});

        while(!pq.empty()){
            auto top=pq.top();
            pq.pop();

            ll dist=top[0];
            ll node=top[1];

            if(dist>distanceTracer[node]) continue;

            for(auto it:graph[node]){
                if(distanceTracer[it.first]>dist+it.second){
                    distanceTracer[it.first]=dist+it.second;
                    pq.push({dist+it.second,it.first});
                    ways[it.first]=ways[node];
                }else if(distanceTracer[it.first]==dist+it.second){
                    ways[it.first]=(ways[it.first]+ways[node])%mod;
                }
            }
        }
        return ways[n-1]%mod;
    }
};