class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<vector<int>>ans;
        priority_queue<pair<int,vector<int>>,vector<pair<int,vector<int>>>
                        ,greater<pair<int,vector<int>>>>pq;
        
        int n=nums1.size(),m=nums2.size();
        for(int i=0;i<n;i++){
            pq.push({nums1[i]+nums2[0],{nums1[i],nums2[0],0}});
        }
        while(k>0 && !pq.empty()){
            auto top=pq.top();
            pq.pop();

            int sum=top.first;
            int ele1=top.second[0];
            int ele2=top.second[1];
            int j=top.second[2];

            ans.push_back({ele1,ele2});
            if(j+1<m){
                pq.push({ele1+nums2[j+1],{ele1,nums2[j+1],j+1}});
            }

            k--;
        }
        return ans;
    }
};