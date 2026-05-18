class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        int size=s.size();
        int greed=g.size();
        int j=0;
        sort(g.begin(),g.end());
        sort(s.begin(),s.end());
        for(int i=0;i<size;i++){
            if(j<greed && s[i]>=g[j]) j++;
        }
        return j;
    }
};