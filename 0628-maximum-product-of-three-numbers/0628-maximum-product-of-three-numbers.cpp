class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        int n=nums.size();
        if(n<3) return -1;
        int fmaxi=INT_MIN,smaxi=INT_MIN,tmaxi=INT_MIN;
        int fmin=INT_MAX,smin=INT_MAX;
        for(auto x:nums){
            if(x>fmaxi){
                tmaxi=smaxi;
                smaxi=fmaxi;
                fmaxi=x;
            }else if(x<=fmaxi && x>smaxi){
                tmaxi=smaxi;
                smaxi=x;
            }else if(x<=smaxi && x<=fmaxi && x>tmaxi){
                tmaxi=x;
            }

            if(x<fmin){
                smin=fmin;
                fmin=x;
            }else if(x>=fmin && x<smin){
                smin=x;
            }
        }
        return max(fmaxi*smaxi*tmaxi,fmaxi*fmin*smin);
    }
};