typedef long long ll;
class Solution {
public:
    long long minimumSteps(string s) {
        ll ans=0;
        ll cnt=0;
        for(char &x:s){
            if(x=='0'){
                ans+=cnt;
            }else{
                cnt++;
            } 
        }
        return ans;
    }
};