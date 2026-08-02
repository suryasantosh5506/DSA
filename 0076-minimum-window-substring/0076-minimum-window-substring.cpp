class Solution {
public:
    string minWindow(string s, string t) {
        int n=s.size();
        int m=t.size();
        unordered_map<char,int>mpp;
        for(char &x:t) mpp[x]++;
        int i=0,j=0;
        int cnt=0;
        int si=-1,len=INT_MAX;
        while(j<n){
            if(mpp[s[j]]>0) cnt++;
            mpp[s[j]]--;
            while(cnt==m){
                if((j-i+1)<len){
                    len=j-i+1;
                    si=i;
                }
                mpp[s[i]]++;
                if(mpp[s[i]]>0) cnt--;
                i++;
            }
            j++;
        }
        return si==-1?"":s.substr(si,len);
    }
};