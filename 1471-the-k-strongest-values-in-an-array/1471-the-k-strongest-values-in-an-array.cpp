class Solution {
public:
    vector<int> getStrongest(vector<int>& arr, int k) {
        sort(arr.begin(),arr.end());
        int n=arr.size();
        int m=arr[(n-1)/2];
        vector<pair<int,int>>diff;
        for(int i=0;i<n;i++){
            diff.emplace_back(abs(arr[i]-m),arr[i]);
        }

        sort(diff.begin(),diff.end(),[](auto &a,auto &b){
            if(a.first==b.first) return a.second>b.second;
            return a.first>b.first;
        });

        vector<int>ans;
        for(int i=0;i<k;i++) ans.emplace_back(diff[i].second);

        return ans;
    }
};