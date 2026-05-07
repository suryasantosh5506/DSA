class Solution {

    int n,m;

    boolean isValid(int i,int j){
        return (i>=0 && i<n) && (j>=0 && j<m);
    }

    int dx[]={-1,0,1,0};
    int dy[]={0,1,0,-1};
    int visited[][];

    int solution(int i,int j,char[][] maze){
        Queue<int[]>q=new LinkedList<>();
        // {row,col,steps} 
        q.offer(new int[]{i,j,0});
        visited[i][j]=1;
        int steps=-1;

        while(!q.isEmpty()){
            int top[]=q.peek();
            q.poll();

            if((top[0] != i || top[1] != j) &&
                (top[0] == 0 || top[1] == 0 ||
                top[0] == n-1 || top[1] == m-1)){
                    steps=top[2];
                    break;
            }

            for(int k=0;k<4;k++){
                int nr=top[0]+dx[k];
                int nc=top[1]+dy[k];

                if(isValid(nr,nc) && maze[nr][nc]!='+' && visited[nr][nc]==0){
                    q.offer(new int[]{nr,nc,top[2]+1});
                    visited[nr][nc]=1;
                }
            }
        }
        return steps;
    }


    public int nearestExit(char[][] maze, int[] entrance) {
        n=maze.length;
        m=maze[0].length;
        visited=new int[n][m];

        for(int i=0;i<n;i++){
            Arrays.fill(visited[i],0);
        }
        return solution(entrance[0],entrance[1],maze);
    }
}