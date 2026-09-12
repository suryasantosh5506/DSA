class Solution {
public:
    vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
        vector<vector<int>>graph(n);
        vector<vector<int>>ans(n);
        vector<int>indegree(n);
        vector<set<int>>temp(n);

        for(auto it:edges){
            graph[it[0]].emplace_back(it[1]);
            indegree[it[1]]++;
        }

        queue<int>q;

        for(int i=0;i<n;i++){
            if(indegree[i]==0) q.push(i);
        }

        while(!q.empty()){
            auto node=q.front();
            q.pop();

            for(auto it:graph[node]){
                temp[it].insert(node);

                for(auto itt:temp[node]){
                    temp[it].insert(itt);
                }

                indegree[it]--;
                if(indegree[it]==0) q.push(it);
            }
        }

        for(int i=0;i<n;i++){
            ans[i]=vector<int>(temp[i].begin(),temp[i].end());
        }
        return ans;
    }
};