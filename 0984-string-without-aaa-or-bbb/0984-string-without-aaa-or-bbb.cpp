class Solution {
public:
    string strWithout3a3b(int a, int b) {
        string ans="";
        while(a>0 || b>0){
            int n=ans.size();
            if(n-2>=0 && ans[n-1]=='a' && ans[n-2]=='a' && b>0){
                ans+='b';
                b--;
            }else if(n-2>=0 && ans[n-1]=='b' && ans[n-2]=='b' && a>0){
                ans+='a';
                a--;
            }else if(a!=0 && a>=b){
                ans+='a';
                a--;
            }else{
                ans+='b';
                b--;
            }
        }
        return ans;
    }
};