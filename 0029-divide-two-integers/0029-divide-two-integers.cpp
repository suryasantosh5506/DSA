typedef long long ll;
class Solution {
public:
    int divide(int dividend, int divisor) {
        int neg=1;
        if((dividend>=0 && divisor<0) || (dividend<0 && divisor>0)) neg=-1;
        ll num=llabs(dividend);
        ll den=llabs(divisor);
        ll ans=0;

        while(num>=den){
            int cnt=0;
            while(num>=den<<(1+cnt)){
                cnt++;
            }
            ans+=(1<<cnt);
            num-=(den<<cnt);
        }
        if(neg==-1 && ans==(1<<31)) return INT_MIN;
        if(neg==1 && ans==(1<<31)) return INT_MAX;
        return neg==-1?-ans:ans;
    }
};