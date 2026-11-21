class Solution {
public:
    int maxConsecutiveAnswers(string s, int k) {
        int n=s.size();
        int t=0,f=0;
        int ans=0;
        int i=0,j=0;
        while(j<n){
            if(s[j]=='T') t++;
            else f++;

            while(min(t,f)>k){
                if(s[i]=='T') t--;
                else f--;
                i++;
            }

            ans=max(ans,j-i+1);
            j++;
        }
        return ans;
    }
};