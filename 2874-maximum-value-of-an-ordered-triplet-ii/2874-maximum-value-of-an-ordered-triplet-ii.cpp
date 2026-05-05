typedef long long ll;
class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        int n=nums.size();
        vector<ll>pre(n),suff(n);
        pre[0]=nums[0];
        suff[n-1]=nums[n-1];

        for(int i=1;i<n;i++){
            pre[i]=max(pre[i-1],(ll)nums[i]);
        }

        for(int i=n-2;i>=0;i--){
            suff[i]=max(suff[i+1],(ll)nums[i]);
        }
        ll ans=LLONG_MIN;

        for(int i=1;i<=n-2;i++){
            ans=max(ans,(pre[i-1]-nums[i])*suff[i+1]);
        }
        return (ans<0)?0:ans;
    }
};