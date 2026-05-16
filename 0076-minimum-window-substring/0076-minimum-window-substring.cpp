class Solution {
public:
    string minWindow(string s, string t) {
        int n=s.size();
        unordered_map<char,int>mpp;
        for(auto x:t) mpp[x]++;
        int si=-1;
        int i=0,j=0;
        int mini=INT_MAX;
        int cnt=0;

        while(j<n){
            if(mpp[s[j]]>0) cnt++;
            mpp[s[j]]--;

            while(cnt==t.size()){
                if((j-i+1)<mini){
                    mini=(j-i+1);
                    si=i;
                }
                mpp[s[i]]++;
                if(mpp[s[i]]>0) cnt--;
                i++;
            }
            j++;
        }
        return (si==-1)?"":s.substr(si,mini);
    }
};