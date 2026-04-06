class Solution {
public:
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        set<vector<int>>st(obstacles.begin(),obstacles.end());
        int n=commands.size();
        int maxi=0;
        int x=0,y=0;
        char direction='N';

        for(int i=0;i<n;i++){
            if(commands[i]==-1){
                if(direction=='N'){
                    direction='E';
                }else if(direction=='S'){
                    direction='W';
                }else if(direction=='E'){
                    direction='S';
                }else if(direction=='W'){
                    direction='N';
                }
            }
            else if(commands[i]==-2){
                if(direction=='N'){
                    direction='W';
                }else if(direction=='S'){
                    direction='E';
                }else if(direction=='E'){
                    direction='N';
                }else if(direction=='W'){
                    direction='S';
                }
            }
            else{
                for(int steps=0;steps<commands[i];steps++){
                    if(direction=='N'){
                        if(st.find({x,y+1})!=st.end()) break;
                        y++;
                    }else if(direction=='E'){
                        if(st.find({x+1,y})!=st.end()) break;
                        x++;
                    }else if(direction=='S'){
                        if(st.find({x,y-1})!=st.end()) break;
                        y--;
                    }else if(direction=='W'){
                        if(st.find({x-1,y})!=st.end()) break;
                        x--;
                    }
                    maxi=max(maxi,x*x+y*y);
                }
            }
        }
        return maxi;
    }
};