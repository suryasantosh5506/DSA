typedef long long ll;
class Solution {
public:
    int myAtoi(string s) {
        int n=s.size();
        int i=0;
        while(i<n){
            if(s[i]==' ') i++;
            else break;
        }
        int sign=1;
        if(i<n && (s[i]=='+' || s[i]=='-')){
            sign=(s[i]=='+')?1:-1;
            i++;
        }

        ll ans=0;
        while(i<n && isdigit(s[i])){
            ans=ans*10+(s[i]-'0');
            if(ans*sign>INT_MAX) return INT_MAX;
            if(ans*sign<INT_MIN) return INT_MIN;
            i++;
        }
        return ans*sign;
    }
};