typedef long long ll;
class Solution {
public:
    int smallestNumber(int n, int t) {
        while(true){
            ll pro=1;
            for(char &ch:to_string(n)){
                pro=1ll*pro*(ch-'0');
            }
            if(pro%t==0) return n;
            n++;
        }
        return -1;
    }
};