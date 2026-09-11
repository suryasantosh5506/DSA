class Solution {
public:

    unordered_map<string,int>dp;

    int solution(int stair,int jump,int k,bool used){
        if(stair<0 || stair>k+1) return 0;

        string s=to_string(stair)+':'+to_string(jump)+':'+to_string(used);
        if(dp.count(s)) return dp[s];

        int cnt=(stair==k);
        if(stair!=0 && !used) cnt+=solution(stair-1,jump,k,true);
        cnt+=solution(stair+(1<<jump),jump+1,k,false);

        return dp[s]=cnt;
    }

    int waysToReachStair(int k) {
        return solution(1,0,k,false);
    }
};