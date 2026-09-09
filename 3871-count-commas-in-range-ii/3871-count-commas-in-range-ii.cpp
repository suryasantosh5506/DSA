typedef long long ll;
class Solution {
public:
    long long countCommas(long long n) {
        ll ans=0;

        for(ll num=1000;num<=n;num*=1000){
            ans+=n-num+1;
        }
        
        return ans;
    }
};