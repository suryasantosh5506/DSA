class FenwickTree{
public:
    vector<int>arr;
    int n;
    FenwickTree(int n){
        this->n=n;
        arr.resize(n+1,0);
    }

    void update(int i,int val){
        while(i<=n){
            arr[i]+=val;
            i=i+(i&(-i));
        }
    }

    int sum(int i){
        int ans=0;
        while(i>0){
            ans+=arr[i];
            i=i&(i-1);
        }
        return ans;
    }
};

class Solution {
public:
    int createSortedArray(vector<int>& instructions) {
        int n=instructions.size();
        int maxi=*max_element(instructions.begin(),instructions.end());
        FenwickTree FWTree(maxi);
        long long ans=0;
        int mod=1e9+7;
        for(int i=0;i<n;i++){
            int x=instructions[i];
            int smaller=FWTree.sum(x-1);
            int greater=i-FWTree.sum(x);
            ans=(ans+min(smaller,greater))%mod;
            FWTree.update(x,1);
        }
        return ans;
    }
};