typedef long long ll;
class Solution {
public:
    const int mod=1e9+7;
    ll myPow(ll x, ll n) {
        bool neg=(n<0);
        ll power=(neg)?-1ll*n:n;
        ll ans=1;
        while(power>0){
            if(power%2==1){
                ans=(ans*x)%mod;
                power--;
            }else{
                x=(x*x)%mod;
                power/=2;
            }
        }
        return ans;
    }

    int countGoodNumbers(long long n) {
        ll evenPos=(n+1)/2;
        ll oddPos=n/2;
        ll oddpossibilities=4,evenpossibilities=5;
        ll even=myPow(evenpossibilities,evenPos);
        ll odd=myPow(oddpossibilities,oddPos);
        return (odd*even)%mod;
    }
};