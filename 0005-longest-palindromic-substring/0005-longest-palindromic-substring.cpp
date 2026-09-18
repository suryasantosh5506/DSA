class Solution {
public:
    string longestPalindrome(string s) {
        int n=s.size();
        int len=0;
        int start=-1;
        for(int i=0;i<n;i++){
            int l=i,r=i;
            while(l>=0 && r<n && s[l]==s[r]){
                if(r-l+1>=len){
                    len=r-l+1;
                    start=l;
                }
                l--;
                r++;
            }

            l=i,r=i+1;
            while(l>=0 && r<n && s[l]==s[r]){
                if(r-l+1>=len){
                    len=r-l+1;
                    start=l;
                }
                l--;
                r++;
            }
        }
        return (start==-1)?"":s.substr(start,len);
    }
};