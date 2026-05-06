typedef long long ll;

class Solution {
  public:
  
    ll solution(ll base,ll power,ll target){
        ll ans=1;
        for(ll i=0;i<power;i++){
            ans*=base;
            if(ans>target) return ans;
        }
        return ans;
    }
  
    int nthRoot(int power, int target) {
        // Code here
        int low=0,high=target;
        while(low<=high){
            int mid=low+(high-low)/2;
            ll value=solution(mid,power,target);
            if(value==target) return mid;
            if(value>target) high=mid-1;
            else low=mid+1;
        }
        return -1;
    }
};