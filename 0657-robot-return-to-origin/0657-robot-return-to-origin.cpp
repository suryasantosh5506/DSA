class Solution {
public:
    bool judgeCircle(string moves) {
        int x=0,y=0;

        for(auto ch:moves){
            if(ch=='R') y++;
            else if(ch=='L') y--;
            else if(ch=='U') x++;
            else x--;
        }
        return x==0 && y==0;
    }
};