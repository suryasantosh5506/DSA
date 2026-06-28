class Solution {
public:
    bool checkValidGrid(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();

        if(grid[0][0]!=0) return false;

        priority_queue<vector<int>,vector<vector<int>>,greater<vector<int>>>pq;
        // {ind,row,col}

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                pq.push({grid[i][j],i,j});
            }
        }

        vector<int>prev=pq.top();
        pq.pop();

        while(!pq.empty()){
            vector<int>curr=pq.top();
            pq.pop();
            if(curr[0]!=prev[0]+1) return false;
            bool cond1=abs(curr[1]-prev[1])==2 && abs(curr[2]-prev[2])==1;
            bool cond2=abs(curr[1]-prev[1])==1 && abs(curr[2]-prev[2])==2;
            if(!cond1 && !cond2) return false;
            prev=curr;
        }
        return true;
    }
};