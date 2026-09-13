class Solution {
public:
    int maxRepOpt1(string text) {
        int maxfreq=INT_MIN;
        unordered_map<char,int>mpp,total;
        char maxch;
        int n=text.size();
        int ans=0;
        int i=0,j=0;

        for(char &x:text) total[x]++;

        while(j<n){
            mpp[text[j]]++;
            if(maxfreq<mpp[text[j]]){
                maxfreq=mpp[text[j]];
                maxch=text[j];
            }
            while((j-i+1)-maxfreq>1){
                mpp[text[i]]--;
                maxfreq=INT_MIN;
                for(auto it:mpp){
                    if(maxfreq<it.second){
                        maxfreq=it.second;
                        maxch=it.first;
                    }
                }
                i++;
            }
            
            ans=max(ans,min(j-i+1,total[maxch]));
            j++;
        }
        return ans;
    }
};