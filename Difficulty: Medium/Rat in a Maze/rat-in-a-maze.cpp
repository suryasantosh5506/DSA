class Solution {
  public:
  
    int n,m;
    
    vector<int> dx={1,0,0,-1};
    vector<int> dy={0,-1,1,0};
    string directions="DLRU";
    
    bool isValid(int i,int j){
        return (i>=0 && i<n) && (j>=0 && j<m);
    }
  
    void solution(int i,int j,string seq,vector<string>&ans,vector<vector<int>>& maze){
        if(i==n-1 && j==m-1){
            ans.emplace_back(seq);
            return;
        }
        maze[i][j]=0;
        
        for(int k=0;k<4;k++){
            int nr=i+dx[k];
            int nc=j+dy[k];
            
            if(isValid(nr,nc) && maze[nr][nc]==1){
                seq+=directions[k];
                solution(nr,nc,seq,ans,maze);
                seq.pop_back();
            }
        }
        maze[i][j]=1;
    }
  
    vector<string> ratInMaze(vector<vector<int>>& maze) {
        // code here
        n=maze.size();
        m=maze[0].size();
        vector<string>ans;
        if(maze[0][0]==0 || maze[n-1][m-1]==0) return ans;
        string seq="";
        solution(0,0,seq,ans,maze);
        return ans;
    }
};