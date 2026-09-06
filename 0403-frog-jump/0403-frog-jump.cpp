class Solution {
public:

    int n;
    unordered_map<string,bool>dp;

    bool solution(int i,int k,vector<int>& stones){
        if(i==n-1) return true;
        string s=to_string(i)+":"+to_string(k);
        if(dp.count(s)) return dp[s];

        for(int j=-1;j<=1;j++){
            int nextjump=k+j;
            if(nextjump<=0) continue;
            int nextposition=stones[i]+nextjump;
            for(int next=i+1;next<n;next++){
                if(stones[next]==nextposition){
                    if(solution(next,nextjump,stones)) return dp[s]=true;
                }
            }
        }
        return dp[s]=false;
    }

    bool canCross(vector<int>& stones) {
        n=stones.size();
        if(n<2 || stones[1]!=1) return false;
        return solution(1,1,stones);
    }
};