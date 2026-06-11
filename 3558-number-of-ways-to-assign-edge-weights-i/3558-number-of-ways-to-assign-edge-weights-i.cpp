typedef long long ll;

class Solution {
public:

    const int mod=1e9+7;
    int maxDepth=-1;

     void solution(int root, int parent, int depth,vector<vector<int>>& tree) {
        maxDepth= max(maxDepth,depth);

        for (int &it:tree[root]) {
            if (it!=parent) {
                solution(it,root,depth+1,tree);
            }
        }
    }

    ll mypower(ll base,ll exp){
        ll ans=1;
        while(exp!=0){
            if(exp%2==0){
                base=(base*base)%mod;
                exp/=2;
            }else{
                ans=(ans*base)%mod;
                exp--;
            }
        }
        return ans;
    }

    int assignEdgeWeights(vector<vector<int>>& edges) {
        int n=edges.size();
        vector<vector<int>>tree(n+2);
        for(auto &it:edges){
            tree[it[0]].emplace_back(it[1]);
            tree[it[1]].emplace_back(it[0]);
        }
        solution(1,-1,0,tree);
        if(maxDepth==0) return 0;
        return mypower(2,maxDepth-1);
    }
};