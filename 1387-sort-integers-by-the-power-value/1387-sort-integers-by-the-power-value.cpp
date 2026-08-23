class Solution {
public:

    vector<pair<int,int>>powers;
    unordered_map<int,int>dp;

    int solution(int i){
        if(i==1) return 0;
        if(dp.count(i)) return dp[i];

        int ans=0;
        if(i%2==0) ans=1+solution(i/2);
        else ans=1+solution(3*i+1);

        return dp[i]=ans;
    }

    int getKth(int lo, int hi, int k) {
        for(int i=lo;i<=hi;i++){
            powers.emplace_back(solution(i),i);
        }
        sort(powers.begin(),powers.end());
        return powers[k-1].second;
    }
};