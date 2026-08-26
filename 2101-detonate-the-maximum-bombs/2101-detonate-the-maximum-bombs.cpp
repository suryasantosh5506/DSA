typedef long long ll;
class Solution {
public:

    int n;
    vector<int>visited;
    vector<vector<int>>graph;

    int solution(int node){
        visited[node]=1;
        int ans=1;

        for(auto it:graph[node]){
            if(!visited[it]){
                ans+=solution(it);
            }
        }
        return ans;
    }

    int maximumDetonation(vector<vector<int>>& bombs) {
        n=bombs.size();
        graph.resize(n);

        for(int i=0;i<n;i++){
            ll x1=bombs[i][0];
            ll y1=bombs[i][1];
            ll r=bombs[i][2];

            for(int j=0;j<n;j++){
                if(i==j) continue;

                ll x2=bombs[j][0];
                ll y2=bombs[j][1];

                ll dx=x1-x2;
                ll dy=y1-y2;

                if(dx*dx+dy*dy<=r*r){
                    graph[i].emplace_back(j);
                }
            }
        }
        int ans=0;
        for(int i=0;i<n;i++){
            visited.assign(n,0);
            ans=max(ans,solution(i));
        }
        return ans;
    }
};