class Solution {
public:
    vector<string> watchedVideosByFriends(vector<vector<string>>& watchedVideos, vector<vector<int>>& friends, int id, int level) {
        int n=friends.size();
        vector<int>visited(n,0);
        queue<int>q;
        int lev=0;
        q.push(id);
        visited[id]=1;

        while(!q.empty()){
            if(lev==level) break;
            int size=q.size();

            for(int i=0;i<size;i++){
                auto top=q.front();
                q.pop();

                for(auto it:friends[top]){
                    if(visited[it]) continue;
                    visited[it]=1;
                    q.push(it);
                }
            }
            lev++;
        }

        unordered_map<string,int>mpp;
        while(!q.empty()){
            auto top=q.front();
            q.pop();
            for(auto it:watchedVideos[top]) mpp[it]++;
        }
        vector<pair<string,int>>arr;
        for(auto it:mpp) arr.emplace_back(it);
        sort(arr.begin(),arr.end(),[&](auto &a,auto &b){
            if(a.second==b.second) return a.first<b.first;
            return a.second<b.second;
        });
        vector<string>ans;
        for(auto it:arr) ans.emplace_back(it.first);
        return ans;
    }
};