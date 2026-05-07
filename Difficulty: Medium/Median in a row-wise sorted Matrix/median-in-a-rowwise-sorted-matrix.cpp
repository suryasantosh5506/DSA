class Solution {
  public:
  
    int blackbox(int tgt,vector<int>&arr){
        int n=arr.size();
        int low=0,high=n-1;
        while(low<=high){
            int mid=low+(high-low)/2;
            if(arr[mid]<=tgt) low=mid+1;
            else high=mid-1;
        }
        return low;
    }
  
    int solution(int tgt,vector<vector<int>>&arr){
        int n=arr.size();
        int m=arr[0].size();
        int ans=0;
        
        for(int i=0;i<n;i++){
            ans+=blackbox(tgt,arr[i]);
        }
        return ans;
    }
  
    int median(vector<vector<int>> &mat) {
        // code here
        int n=mat.size();
        int m=mat[0].size();
        
        int req=(n*m)/2;
        int low=INT_MAX,high=INT_MIN;
        for(int i=0;i<n;i++){
            low=min(low,mat[i][0]);
            high=max(high,mat[i][m-1]);
        }
        int ans=-1;
        while(low<=high){
            int mid=low+(high-low)/2;
            
            int lte=solution(mid,mat);
            if(lte>req){
                ans=mid;
                high=mid-1;
            }else{
                low=mid+1;
            }
        }
        return ans;
    }
};
