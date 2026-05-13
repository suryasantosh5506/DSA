class Solution {
public:
    int minFlips(int a, int b, int c) {
        int cnt=0;
        while(a!=0 || b!=0 || c!=0){
            int b1=a%2;
            int b2=b%2;
            int tgt=c%2;

            if((b1|b2)!=tgt){
                if(tgt == 1) cnt += 1;
                else cnt += b1 + b2;
            }

            a/=2;
            b/=2;
            c/=2;
        }
        return cnt;
    }
};