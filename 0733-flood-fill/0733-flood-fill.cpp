class Solution {
public:

    vector<vector<int>>visited;
    int n,m;
    vector<int>dx={0,1,0,-1};
    vector<int>dy={-1,0,1,0};

    bool isValid(int i,int j){
        return (i>=0 && i<n) && (j>=0 && j<m);
    }

    void solution(int i,int j,int ori,int color,vector<vector<int>>& image){
        visited[i][j]=1;
        image[i][j]=color;

        for(int k=0;k<4;k++){
            int nr=i+dx[k];
            int nc=j+dy[k];

            if(isValid(nr,nc) && !visited[nr][nc] && image[nr][nc]==ori){
                solution(nr,nc,ori,color,image);
            }
        }

    }

    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        n=image.size();
        m=image[0].size();
        visited.assign(n,vector<int>(m,0));
        solution(sr,sc,image[sr][sc],color,image);
        return image;
    }
};