class DisJointSet{
public:
    vector<int>rank;
    vector<int>parent;

    DisJointSet(int n){
        rank.resize(n+1,0);
        parent.resize(n+1);

        for(int i=0;i<=n;i++){
            parent[i]=i;
        }
    }

    int fup(int u){
        if(parent[u]==u) return u;
        return parent[u]=fup(parent[u]);
    }

    void unionByRank(int u,int v){
        int pu=fup(u);
        int pv=fup(v);
        if(pu==pv) return;
        if(rank[pu]<rank[pv]){
            parent[pu]=pv;
        }else if(rank[pv]<rank[pu]){
            parent[pv]=pu;
        }else{
            parent[pv]=pu;
            rank[pu]++;
        }
    }
};

class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        unordered_map<string,int>mpp;
        int n=accounts.size();
        DisJointSet ds(n+1);
        
        for(int i=0;i<n;i++){
            for(int j=1;j<accounts[i].size();j++){
                if(mpp.count(accounts[i][j])){
                    ds.unionByRank(i,mpp[accounts[i][j]]);
                }else{
                    mpp[accounts[i][j]]=i;
                }
            }
        }

        vector<vector<string>>mails(n);
        for(auto it:mpp){
            string mail=it.first;
            int node=ds.fup(it.second);
            mails[node].emplace_back(mail);
        }

        vector<vector<string>>ans;
        for(int i=0;i<n;i++){
            if(mails[i].size()==0) continue;
            vector<string>temp;
            temp.emplace_back(accounts[i][0]);
            sort(mails[i].begin(),mails[i].end());
            temp.insert(temp.end(),mails[i].begin(),mails[i].end());
            ans.emplace_back(temp);
        }

        return ans;
    }
};