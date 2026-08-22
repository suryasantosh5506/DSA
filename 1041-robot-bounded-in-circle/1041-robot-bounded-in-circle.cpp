class Solution {
public:
    bool isRobotBounded(string instructions) {
        vector<int>point={0,0};
        char dir='n';

        for(char &x:instructions){
            if(x=='G'){
                if(dir=='n') point[1]+=1;
                else if(dir=='s') point[1]-=1;
                else if(dir=='e') point[0]+=1;
                else if(dir=='w') point[0]-=1;
            }else if(x=='L'){
                if(dir=='n') dir='w';
                else if(dir=='w') dir='s';
                else if(dir=='s') dir='e';
                else if(dir=='e') dir='n';
            }else{
                if(dir=='n') dir='e';
                else if(dir=='e') dir='s';
                else if(dir=='s') dir='w';
                else if(dir=='w') dir='n';
            }
        }
        return (point[0]==0 && point[1]==0) || dir != 'n';
    }
};