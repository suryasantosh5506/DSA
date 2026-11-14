class LockingTree {
public:

    int n;
    vector<vector<int>>tree;
    unordered_map<int,int>lockednodes;
    unordered_map<int,vector<int>>ancestors;

    void bfs(int root){
        queue<int>q;
        q.push(root);
        ancestors[root] = {};

        while(!q.empty()){
            int top=q.front();
            q.pop();

            for(int &x:tree[top]){
                ancestors[x]=ancestors[top];
                ancestors[x].emplace_back(top);
                q.push(x);
            }
        }
    }

    LockingTree(vector<int>& parent) {
        n=parent.size();
        tree.resize(n);
        for(int i=0;i<n;i++){
            if(parent[i]==-1) continue;
            tree[parent[i]].emplace_back(i);
        }
        bfs(0);
    }
    
    bool isdescendantlocked(int node){
        bool ans=false;
        for(int &x:tree[node]){
            if(lockednodes.count(x)) return true;
            ans|=isdescendantlocked(x);
            if(ans) return ans;
        }
        return ans;
    }

    bool isancestorslocked(int node){
        for(int &x:ancestors[node]){
            if(lockednodes.count(x)) return true;
        }
        return false;
    }

    bool lock(int num, int user) {
        if(lockednodes.count(num)) return false;
        lockednodes[num]=user;
        return true;
    }
    
    bool unlock(int num, int user) {
        if(!lockednodes.count(num)) return false;
        if(lockednodes[num]!=user) return false;
        lockednodes.erase(num);
        return true;
    }
    
    void unlockdescendants(int node){
        for(int &x:tree[node]){
            if(lockednodes.count(x)) lockednodes.erase(x);
            unlockdescendants(x);
        }
    }

    bool upgrade(int num, int user) {
        if(lockednodes.count(num)) return false;
        if(!isdescendantlocked(num)) return false;
        if(isancestorslocked(num)) return false;
        lockednodes[num]=user;
        unlockdescendants(num);
        return true;
    }
};

/**
 * Your LockingTree object will be instantiated and called as such:
 * LockingTree* obj = new LockingTree(parent);
 * bool param_1 = obj->lock(num,user);
 * bool param_2 = obj->unlock(num,user);
 * bool param_3 = obj->upgrade(num,user);
 */