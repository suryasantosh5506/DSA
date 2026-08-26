class Solution {
public:
    bool canReorderDoubled(vector<int>& arr) {
        unordered_map<int,int>mpp;
        for(int &x:arr) mpp[x]++;
        sort(arr.begin(),arr.end(),[](auto &a,auto &b){
            return abs(a)<abs(b);
        });

        for(int &x:arr){
            if(mpp[x]==0) continue;
            if(mpp[2*x]==0) return false;
            mpp[x]--;
            mpp[2*x]--;
        }
        return true;
    }
};