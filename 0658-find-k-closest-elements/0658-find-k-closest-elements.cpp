class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        vector<pair<int,int>>dist;
        for(int &p:arr) dist.emplace_back(abs(x-p),p);
        sort(dist.begin(),dist.end());
        vector<int>ans;
        for(int i=0;i<k;i++) ans.emplace_back(dist[i].second);
        sort(ans.begin(),ans.end());
        return ans;
    }
};