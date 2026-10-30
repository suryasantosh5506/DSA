typedef long long ll;
class Solution {
public:
    double myPow(double x, int n) {
        double ans=1;
        bool neg=(n<0);
        ll pow=llabs(n);
        while(pow>0){
            if(pow%2==0){
                x*=x;
                pow/=2;
            }else{
                ans*=x;
                pow--;
            }
        }
        return (neg)?1/ans:ans;
    }
};