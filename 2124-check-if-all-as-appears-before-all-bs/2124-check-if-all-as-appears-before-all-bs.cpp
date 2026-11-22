class Solution {
public:
    bool checkString(string s) {
        int a=-1,b=-1;
        int n=s.size();
        for(int i=0;i<n;i++){
            if(s[i]=='a') a=i;
            if(s[i]=='b') b=i;
            if(b!=-1 && a>b) return false;
        }
        return true;
    }
};