typedef long long ll;
class Solution {
public:
    double myPow(double x, int n) {
        bool neg=(n<0);
        ll power=(neg)?-1ll*n:n;
        double ans=1;
        while(power>0){
            if(power%2==1){
                ans*=x;
                power--;
            }else{
                x*=x;
                power/=2;
            }
        }
        return (neg)?1/ans:ans;
    }
};