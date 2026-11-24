class Solution {
public:

    vector<vector<int>>groupgraph;
    vector<vector<int>>itemgraph;
    vector<int>itemvisited,ipathvisited;
    vector<int>groupvisited,gpathvisited;
    vector<int>groupOrder;
    vector<vector<int>>itemsingroup;

    bool grouptoposort(int group){
        groupvisited[group]=1;
        gpathvisited[group]=1;

        for(auto it:groupgraph[group]){
            if(!groupvisited[it]){
                if(!grouptoposort(it)) return false;
            }else if(gpathvisited[it]) return false;
        }

        gpathvisited[group]=false;
        groupOrder.emplace_back(group);
        return true;
    }

    bool itemtoposort(int item,int gid,vector<int>&order,vector<int>&group){
        itemvisited[item]=1;
        ipathvisited[item]=1;

        for(auto it:itemgraph[item]){
            if(group[it]!=gid) continue;
            if(!itemvisited[it]){
                if(!itemtoposort(it,gid,order,group)) return false;
            }else if(ipathvisited[it]) return false;
        }

        ipathvisited[item]=false;
        order.emplace_back(item);
        return true;
    }

    vector<int> sortItems(int n, int m, vector<int>& group, vector<vector<int>>& beforeItems) {
        itemvisited.assign(n,0);
        ipathvisited.assign(n,0);
        itemgraph.resize(n);

        for(int &x:group) if(x==-1) x=m++;

        groupvisited.assign(m,0);
        gpathvisited.assign(m,0);
        groupgraph.resize(m);
        itemsingroup.resize(m);
        vector<int>ans;

        for(int i=0;i<n;i++){
            itemsingroup[group[i]].push_back(i);
            for(int &prev:beforeItems[i]){
                itemgraph[prev].emplace_back(i);
                if(group[i]!=group[prev]){
                    groupgraph[group[prev]].emplace_back(group[i]);
                }
            }
        }

        for(int i=0;i<m;i++){
            if(!groupvisited[i]){
                if(!grouptoposort(i)) return {};
            }
        }

        reverse(groupOrder.begin(),groupOrder.end());

        for(auto g:groupOrder){
            vector<int>order;
            for(auto it:itemsingroup[g]){
                if(itemvisited[it]) continue;
                if(!itemtoposort(it,g,order,group)) return {};
            }
            reverse(order.begin(),order.end());
            for(int &x:order) ans.emplace_back(x);
        }

        return ans;
    }
};