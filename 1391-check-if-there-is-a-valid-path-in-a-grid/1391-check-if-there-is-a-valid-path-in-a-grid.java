class Solution {

    Map<Integer, int[][]> mpp = new HashMap<>();
    int n, m;
    int[][] visited;

    boolean isValid(int i, int j){
        return i >= 0 && i < n && j >= 0 && j < m;
    }

    boolean solution(int i, int j, int[][] grid){
        if(i == n-1 && j == m-1) return true;

        visited[i][j] = 1;

        int[][] directions = mpp.get(grid[i][j]);

        for(int[] dir : directions){
            int dx = i + dir[0];
            int dy = j + dir[1];

            if(!isValid(dx, dy) || visited[dx][dy] == 1) continue;

            // check reverse connection
            boolean ok = false;
            for(int[] back : mpp.get(grid[dx][dy])){
                if(dx + back[0] == i && dy + back[1] == j){
                    ok = true;
                    break;
                }
            }

            if(ok && solution(dx, dy, grid)){
                return true;
            }
        }
        return false;
    }

    public boolean hasValidPath(int[][] grid) {
        mpp.put(1, new int[][]{{0,-1},{0,1}});
        mpp.put(2, new int[][]{{1,0},{-1,0}});
        mpp.put(3, new int[][]{{0,-1},{1,0}});
        mpp.put(4, new int[][]{{0,1},{1,0}});
        mpp.put(5, new int[][]{{0,-1},{-1,0}});
        mpp.put(6, new int[][]{{0,1},{-1,0}});

        n = grid.length;
        m = grid[0].length;

        visited = new int[n][m];

        return solution(0, 0, grid);
    }
}