class Solution {
public:

    vector<int>dx={0,1};
    vector<int>dy={1,0};
    int n,m;
    unordered_map<string,bool>visited;

    bool isValid(int i,int j){
        return (i>=0 && i<n) && (j>=0 && j<m);
    }

    bool solution(int i,int j,int balance,vector<vector<char>>& grid){
        if(balance<0) return false;
        
        string s=to_string(i)+','+to_string(j)+','+to_string(balance);
        if(visited.count(s)) return visited[s];

        if(grid[i][j]=='(') balance++;
        else balance--;

        if(i==n-1 && j==m-1) return balance==0;
        for(int k=0;k<2;k++){
            int nr=i+dx[k],nc=j+dy[k];
            
            if(isValid(nr,nc)){
                if(solution(nr,nc,balance,grid)) return visited[s]=true;
            }
        }
        return visited[s]=false;
    }

    bool hasValidPath(vector<vector<char>>& grid) {
        n=grid.size();
        m=grid[0].size();
        if (grid[0][0] == ')' || grid[n - 1][m - 1] == '(') {
            return false;
        }
        return solution(0,0,0,grid);
    }
};