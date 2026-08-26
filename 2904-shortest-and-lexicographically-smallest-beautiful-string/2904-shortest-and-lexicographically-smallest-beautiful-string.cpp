class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        string ans="";
        int start=-1;
        int i=0,j=0;
        int n=s.size();
        int ones=0;

        while(j<n){
            ones+=(s[j]=='1');

            while(ones==k){
                if(start==-1 || (j-i+1==ans.size() && s.substr(i,j-i+1)<ans) || j-i+1<ans.size()){
                    ans=s.substr(i,j-i+1);
                    start=i;
                }
                ones-=(s[i]=='1');
                i++;
            }
            j++;
        }
        return ans;
    }
};