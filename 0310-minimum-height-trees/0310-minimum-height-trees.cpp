class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        if(edges.empty() && n==1) return {0};
        vector<int>ans;
        vector<int>indegree(n,0);
        vector<vector<int>>tree(n);
        for(auto it:edges){
            tree[it[0]].emplace_back(it[1]);
            tree[it[1]].emplace_back(it[0]);
            indegree[it[0]]++;
            indegree[it[1]]++;
        }

        int remaining=n;
        queue<int>q;
        for(int i=0;i<n;i++) if(indegree[i]==1) q.push(i);

        while(remaining>2){
            int size=q.size();
            remaining-=size;
            
            for(int i=0;i<size;i++){
                int top=q.front();
                q.pop();

                for(auto it:tree[top]){
                    indegree[it]--;
                    if(indegree[it]==1) q.push(it);
                }
            }
        }

        while(!q.empty()){
            ans.emplace_back(q.front());
            q.pop();
        }
        return ans;
    }
};