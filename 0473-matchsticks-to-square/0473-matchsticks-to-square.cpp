class Solution {
public:

    bool solution(int i,int left,int right,int top,int bottom,int req,vector<int>&matchsticks){
        if(i==matchsticks.size()){
            return(left==req&&right==req&&top==req&&bottom==req);
        }
        if(left>req || right>req || top>req || bottom>req) return false;
        if(solution(i+1,left+matchsticks[i],right,top,bottom,req,matchsticks)) return true;
        if(solution(i+1,left,right+matchsticks[i],top,bottom,req,matchsticks)) return true;
        if(solution(i+1,left,right,top+matchsticks[i],bottom,req,matchsticks)) return true;
        if(solution(i+1,left,right,top,bottom+matchsticks[i],req,matchsticks)) return true;
        return false;
    }

    bool makesquare(vector<int>& matchsticks) {
        int sum=accumulate(matchsticks.begin(),matchsticks.end(),0);
        sort(matchsticks.rbegin(),matchsticks.rend());
        if(sum%4!=0) return false;
        int req=sum/4;
        return solution(0,0,0,0,0,req,matchsticks);
    }
};