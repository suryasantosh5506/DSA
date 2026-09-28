class Solution {
public:
    int maxDepth(string s) {
        int maxi=0,cnt=0;
        for(char &x:s){
            if(x=='(') cnt++;
            else if(x==')') cnt--;
            maxi=max(maxi,cnt);
        }
        return maxi;
    }
};