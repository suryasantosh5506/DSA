class Solution {
public:
    vector<int> kthSmallestPrimeFraction(vector<int>& arr, int k) {
        vector<pair<double,vector<int>>>ans;
        // {a/b,{a,b}}
        int n=arr.size();
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                ans.push_back({arr[i]/(double)arr[j],{arr[i],arr[j]}});
            }
        }
        sort(ans.begin(),ans.end());
        return ans[k-1].second;
    }
};