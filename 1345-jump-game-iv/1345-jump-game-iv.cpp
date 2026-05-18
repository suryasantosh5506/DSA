class Solution {
public:
    int minJumps(vector<int>& arr) {
        int n=arr.size();
        queue<pair<int,int>>q;
        vector<int>visited(n,0);
        q.push({0,0});
        // {index,steps}
        visited[0]=1;

        unordered_map<int,vector<int>> mpp;
        for(int i=0;i<n;i++){
            mpp[arr[i]].push_back(i);
        }

        while(!q.empty()){
            auto top=q.front();
            q.pop();

            int i=top.first;
            int steps=top.second;

            if(i==n-1) return steps;

            if(i-1>=0 && !visited[i-1]){
                q.push({i-1,steps+1});
                visited[i-1]=1;
            }
            if(i+1<n && !visited[i+1]){
                q.push({i+1,steps+1});
                visited[i+1]=1;
            }

            for(auto j:mpp[arr[i]]){
                if(visited[j]) continue;
                q.push({j,steps+1});
            }
            mpp[arr[i]].clear();
        }
        return -1;
    }
};