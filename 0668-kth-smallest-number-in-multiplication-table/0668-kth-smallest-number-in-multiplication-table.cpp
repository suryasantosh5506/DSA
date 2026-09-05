class Solution {
public:
    int findKthNumber(int n, int m, int k) {
        int low=1,high=n*m;
        int ans=-1;
        while(low<=high){
            int mid=low+(high-low)/2;
            int cnt=0;
            for(int i=1;i<=n;i++){
                cnt+=min(m,mid/i);
            }

            if(cnt>=k){
                ans=mid;
                high=mid-1;
            }else{
                low=mid+1;
            }
        }
        return ans;
    }
};