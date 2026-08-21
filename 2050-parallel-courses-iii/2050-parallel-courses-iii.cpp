class Solution {
public:
    int minimumTime(int n, vector<vector<int>>& relations, vector<int>& time) {
        vector<vector<int>>graph(n+1);
        vector<int>indegree(n+1,0);
        vector<int>timetaken(n+1,INT_MIN);

        for(auto it:relations){
            graph[it[0]].emplace_back(it[1]);
            indegree[it[1]]++;
        }
        
        queue<vector<int>>q;
        // {node,dist};
        
        for(int i=1;i<=n;i++){
            if(indegree[i]==0){
                q.push({i,time[i-1]});
                timetaken[i]=time[i-1];
            }
        }
        
        int maxi=0;

        while(!q.empty()){
            auto top=q.front();
            q.pop();

            int node=top[0];
            int t=top[1];

            maxi=max(maxi,t);

            for(auto it:graph[node]){
                timetaken[it]=max(timetaken[it],timetaken[node]+time[it-1]);
                indegree[it]--;
                if(indegree[it]==0){
                    q.push({it,timetaken[it]});
                }
            }
        }
        return maxi;
    }
};