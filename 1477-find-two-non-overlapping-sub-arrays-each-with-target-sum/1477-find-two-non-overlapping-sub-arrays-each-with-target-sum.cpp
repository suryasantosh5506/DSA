class Solution {
public:
    int minSumOfLengths(vector<int>& arr, int target) {
        int n=arr.size();
        int l=0,sum=0;
        vector<int>pre(n,1e8),suff(n,1e8);
        for(int r=0;r<n;r++){
            sum+=arr[r];
            while(sum>target) sum-=arr[l++];
            if(sum==target) pre[r]=r-l+1;
            if(r>0) pre[r]=min(pre[r-1],pre[r]);
        }

        l=n-1,sum=0;
        for(int r=n-1;r>=0;r--){
            sum+=arr[r];
            while(sum>target) sum-=arr[l--];
            if(sum==target) suff[r]=(l-r+1);
            if(r<n-1) suff[r]=min(suff[r],suff[r+1]);
        }

        int ans=1e8;
        for(int i=0;i<n-1;i++){
            if(pre[i]!=1e8 && suff[i+1]!=1e8) ans=min(ans,pre[i]+suff[i+1]);
        }
        return ans==1e8?-1:ans;
    }
};