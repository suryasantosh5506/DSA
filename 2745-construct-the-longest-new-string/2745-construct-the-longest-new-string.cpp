class Solution {
public:

    vector<vector<vector<vector<int>>>>dp;

    int solution(int prev,int x,int y,int z){
        if(x==0 && y==0 && z==0) return 0;
        if(dp[prev][x][y][z]!=-1) return dp[prev][x][y][z];

        int ans=0;
        if(prev!=1 && x>0) ans=max(ans,2+solution(1,x-1,y,z));
        if(prev!=2 && prev!=3 && y>0) ans=max(ans,2+solution(2,x,y-1,z));
        if(prev!=1 && z>0) ans=max(ans,2+solution(3,x,y,z-1));

        return dp[prev][x][y][z]=ans;
    }

    int longestString(int x, int y, int z) {
        dp.assign(4,
            vector<vector<vector<int>>>(x+1,
                vector<vector<int>>(y+1,
                    vector<int>(z+1,-1)
                )
            )
        );
        return solution(0,x,y,z);
    }
};