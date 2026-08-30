class Solution {
public:
    bool closeStrings(string word1, string word2) {
        unordered_map<char,int>smap,tmap;
        for(char &x:word1) smap[x]++;
        for(char &x:word2){
            if(!smap.count(x)) return false;
            tmap[x]++;
        }

        unordered_map<int,int>freqdiff;
        for(auto it:smap) freqdiff[it.second]++;
        for(auto it:tmap) freqdiff[it.second]--;
        for(auto it:freqdiff) if(it.second!=0) return false;
        return true;
    }
};