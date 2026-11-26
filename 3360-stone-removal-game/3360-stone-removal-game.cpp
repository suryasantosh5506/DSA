class Solution {
public:
    bool canAliceWin(int n) {
        if(n<10) return false;
        int remove=10;
        int turn=0;
        while(n>=remove){
            n-=remove;
            turn=!turn;
            remove--;
        }
        return turn==1;
    }
};