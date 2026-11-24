class Solution {
public:
    int maxLength(vector<int>& nums) {
        int n=nums.size();
        int ans=0;
        int pro=nums[0];
        int l=nums[0],g=nums[0];
        int i=0,j=1;
        while(j<n){
            pro*=nums[j];
            g=gcd(g,nums[j]);
            l=lcm(l,nums[j]);
            while(pro>l*g){
                i++;
                g=0,l=1,pro=1;
                for(int k=i;k<=j;k++) {
                    g=gcd(g,nums[k]);
                    l=lcm(l, nums[k]);
                    pro*=nums[k];
                }
            }
            if(pro==l*g) ans=max(ans,j-i+1);
            j++;
        }
        return ans;
    }
};