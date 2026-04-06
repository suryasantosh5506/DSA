class Solution {
    public int robotSim(int[] commands, int[][] obstacles) {
        Set<List<Integer>>st=new HashSet();

        for(int i = 0; i < obstacles.length; i++){
            st.add(Arrays.asList(obstacles[i][0], obstacles[i][1]));
        }

        int n=commands.length;
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
                        if(st.contains(Arrays.asList(x,y+1))) break;
                        y++;
                    }else if(direction=='E'){
                        if(st.contains(Arrays.asList(x+1,y))) break;
                        x++;
                    }else if(direction=='S'){
                        if(st.contains(Arrays.asList(x,y-1))) break;
                        y--;
                    }else if(direction=='W'){
                        if(st.contains(Arrays.asList(x-1,y))) break;
                        x--;
                    }
                    maxi=Math.max(maxi,x*x+y*y);
                }
            }
        }
        return maxi;
    }
}