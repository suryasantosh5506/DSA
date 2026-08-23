typedef long long ll;

class Solution {
public:

    int n;
    map<vector<ll>,int>dp;

    int solution(int i,ll num,ll den,vector<int>& nums, ll k){
        if(i==n)  return num/den==k && num%den==0;
        vector<ll>temp={i,num,den};
        if(dp.count(temp)) return dp[temp];

        int ans=0;

        ll newnum=num*1ll*nums[i];
        ll g=gcd(newnum,den);
        ans+=solution(i+1,newnum/g,den/g,nums,k);

        ll newden=den*1ll*nums[i];
        g=gcd(num,newden);
        ans+=solution(i+1,num/g,newden/g,nums,k);

        ans+=solution(i+1,num,den,nums,k);

        return dp[temp]=ans;
    }

    int countSequences(vector<int>& nums, long long k) {
        n=nums.size();
        return solution(0,1,1,nums,k);
    }
};