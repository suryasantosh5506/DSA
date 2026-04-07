class Robot {
public:

    int n,m;
    int x=0,y=0;
    string direction="East";

    Robot(int width, int height) {
        n=width;
        m=height;
    }
    
    void step(int num) {
        int cycle = 2 * (n + m - 2);
        int steps = num % cycle;

        if (steps == 0) {
            steps = cycle;
        }

        for(int i=0;i<steps;i++){
            if(direction=="East"){
                if(x+1>=n){
                    direction="North";
                    y++;
                }else {
                    x++;
                }
            }else if(direction=="West"){
                if(x-1<0){
                    direction="South";
                    y--;
                }else{
                    x--;
                }
            }else if(direction=="North"){
                if(y+1>=m){
                    direction="West";
                    x--;
                }else{
                    y++;
                }
            }else if(direction=="South"){
                if(y-1<0){
                    direction="East";
                    x++;
                }else{
                    y--;
                }
            }
        }
    }
    
    vector<int> getPos() {
        return {x,y};
    }
    
    string getDir() {
        return direction;
    }
};

/**
 * Your Robot object will be instantiated and called as such:
 * Robot* obj = new Robot(width, height);
 * obj->step(num);
 * vector<int> param_2 = obj->getPos();
 * string param_3 = obj->getDir();
 */