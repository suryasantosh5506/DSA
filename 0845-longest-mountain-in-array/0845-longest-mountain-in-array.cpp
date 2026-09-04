class Solution {
public:
    int longestMountain(vector<int>& arr) {
        int n=arr.size();
        if(n<3) return 0;
        vector<int>left(n),right(n);
        left[0]=0,right[n-1]=0;
        for(int i=1;i<n;i++) if(arr[i-1]<arr[i]) left[i]=left[i-1]+1;
        for(int i=n-2;i>=0;i--) if(arr[i+1]<arr[i]) right[i]=right[i+1]+1;
        int ans=0;
        for(int i=1;i<n-1;i++) if(left[i]>0 && right[i]>0) ans=max(ans,left[i]+right[i]+1);
        return ans<3?0:ans;
    }
};