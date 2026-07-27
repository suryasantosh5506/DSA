class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int fmaxi=INT_MIN,smaxi=INT_MIN;
        for(int &x:nums){
            if(x>fmaxi){
                smaxi=fmaxi;
                fmaxi=x;
            }else if(x<=fmaxi && x>smaxi){
                smaxi=x;
            }
        }
        return (fmaxi-1)*(smaxi-1);
    }
};