typedef long long ll;
class Solution {
public:
    long long maxSum(vector<vector<int>>& grid, vector<int>& limits, int k) {
        int n=grid.size(),m=grid[0].size();
        priority_queue<int,vector<int>,greater<int>>pq;
        for(int i=0;i<n;i++) sort(grid[i].rbegin(),grid[i].rend());
        for(int i=0;i<n;i++){
            for(int j=0;j<min(limits[i],m);j++){
                pq.push(grid[i][j]);
                if(pq.size()>k) pq.pop();
            }
        }
        ll sum=0;
        while(!pq.empty()){
            sum+=pq.top();
            pq.pop();
        }
        return sum;
    }
};