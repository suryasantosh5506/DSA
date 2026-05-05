typedef long long ll;
class Solution {
  public:
    vector<int> findTwoElement(vector<int>& arr) {
        // code here
        
        int n=arr.size();
        
        ll s1=0,s2=0;
        ll sq1=0,sq2=0;
        
        for(int i=0;i<n;i++){
            s1+=i+1;
            s2+=arr[i];
            sq1+=(1ll*(i+1)*(i+1));
            sq2+=(1ll*arr[i]*arr[i]);
        }
        
        ll eq1=s1-s2;
        ll eq2=sq1-sq2;
        
        ll aplusb=eq2/eq1;
        ll a=(aplusb+eq1)/2;
        ll b=aplusb-a;
        return {b,a};
    }
};
