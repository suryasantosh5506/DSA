class Solution {
public:
    int minSteps(string s, string t) {
        unordered_map<char,int>smap,tmap;
        for(char &x:s) smap[x]++;
        for(char &x:t) tmap[x]++;

        for(char &x:s) tmap[x]--;
        for(char &x:t) smap[x]--;

        int ans=0;
        for(auto it:smap) if(it.second<0) ans+=abs(it.second);
        for(auto it:tmap) if(it.second<0) ans+=abs(it.second);

        return ans;
    }
};