typedef long long ll;
class Solution {
public:
    long long sumAndMultiply(int n) {
        if(n==0) return 0;
        string num=to_string(n);
        string res="";
        ll sum=0;
        for(char &x:num){
            if(x!='0') res+=x;
            sum+=(x-'0');
        }
        ll ori=stoll(res)*sum;
        return ori;
    }
};