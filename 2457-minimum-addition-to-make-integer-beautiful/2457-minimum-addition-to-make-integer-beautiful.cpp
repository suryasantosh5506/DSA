typedef long long ll;
class Solution {
public:

    ll getsum(ll n){
        ll sum=0;
        while(n>0){
            sum+=n%10;
            n/=10;
        }
        return sum;
    }

    long long makeIntegerBeautiful(long long n, int target) {
        ll place=1;
        ll ori=n;
        while(getsum(n)>target){
            int digitatplace=(n/place)%10;
            int digittoaddtomake0=(10-digitatplace);
            n+=(digittoaddtomake0)*place;
            place*=10;
        }
        return n-ori;
    }
};
