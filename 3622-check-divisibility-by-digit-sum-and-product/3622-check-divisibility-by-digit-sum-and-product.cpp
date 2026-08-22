typedef long long ll;
class Solution {
public:
    bool checkDivisibility(int n) {
        ll pro=1,sum=0;
        for(char &ch:to_string(n)){
            pro*=1ll*(ch-'0');
            sum+=(ch-'0');
        }
        return (n%(sum+pro))==0;
    }
};