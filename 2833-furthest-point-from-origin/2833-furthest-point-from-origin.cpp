class Solution {
public:
    int furthestDistanceFromOrigin(string moves) {
        int l=0,r=0,dash=0;
        for(auto x:moves){
            if(x=='L') l++;
            else if(x=='R') r++;
            else dash++;
        }
        return dash+max(l,r)-min(l,r);
    }
};