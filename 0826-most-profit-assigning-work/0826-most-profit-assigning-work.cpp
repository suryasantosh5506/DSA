class Solution {
public:
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
        vector<pair<int,int>>arr;
        int n=profit.size();
        for(int i=0;i<n;i++){
            arr.emplace_back(profit[i],difficulty[i]);
        }
        sort(arr.begin(),arr.end(),[](auto a,auto b){
            if(a.first==b.first) return a.second<b.second;
            return a.first>b.first;
        });
        sort(worker.rbegin(),worker.rend());
        int i=0,j=0;
        int m=worker.size();
        int ans=0;
        while(i<n && j<m){
            if(arr[i].second<=worker[j]){
                ans+=arr[i].first;
                j++;
            }else{
                i++;
            }
        }
        return ans;
    }
};