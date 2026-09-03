class Solution {
public:
    int magicalString(int n) {
        string s="122";
        int i=2;
        char ch='1';
        int ones=1;
        while(s.size()<n){
            int cnt=(s[i])-'0';
            s+=string(cnt,ch);
            ones+=(ch=='1'?cnt:0);
            ch=(ch=='1')?'2':'1';
            i++;
        }
        for(int i=n;i<s.size();i++){
            if(s[i]=='1') ones--;
        }
        return ones;
    }
};