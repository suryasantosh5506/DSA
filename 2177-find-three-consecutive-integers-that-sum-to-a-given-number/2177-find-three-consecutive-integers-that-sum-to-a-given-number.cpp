typedef long long ll;
class Solution {
public:
    vector<long long> sumOfThree(long long num) {
        vector<ll>ans;
        if(num %3!=0) return ans;
        ll n=num/3;
        return {n-1,n,n+1};
    }
};