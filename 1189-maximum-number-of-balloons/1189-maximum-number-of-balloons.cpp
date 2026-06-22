class Solution {
public:
    int maxNumberOfBalloons(string text) {
        int b=0,a=0,l=0,o=0,n=0;
        for(char &x:text){
            if(x=='b') b++;
            if(x=='a') a++;
            if(x=='l') l++;
            if(x=='o') o++;
            if(x=='n') n++;
        }
        l/=2;
        o/=2;
        return min({b,a,l,o,n});
    }
};