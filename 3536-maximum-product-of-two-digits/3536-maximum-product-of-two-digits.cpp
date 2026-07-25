class Solution {
public:
    int maxProduct(int n) {
        int fmaxi=INT_MIN,smaxi=INT_MIN;
        for(char &ch:to_string(n)){
            int num=ch-'0';
            if(num>fmaxi){
                smaxi=fmaxi;
                fmaxi=num;
            }else if(num<=fmaxi && num>smaxi){
                smaxi=num;
            }
        }
        return fmaxi*smaxi;
    }
};