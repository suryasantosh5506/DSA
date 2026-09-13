class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        sort(trips.begin(),trips.end(),[](auto &a,auto &b){
            return a[1]<b[1];
        });
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        // {dropout,capacity}
        int curr=0;
        for(auto it:trips){
            while(!pq.empty() && pq.top().first<=it[1]){
                curr-=pq.top().second;
                pq.pop();
            }
            curr+=it[0];
            if(curr>capacity) return false;
            pq.push({it[2],it[0]});
        }
        return true;
    }
};