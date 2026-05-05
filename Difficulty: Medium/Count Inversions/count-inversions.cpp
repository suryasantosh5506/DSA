class Solution {
  public:
  
    int merge(int low,int mid,int high,vector<int>&arr){
        vector<int>temp;
        int i=low,j=mid+1;
        int cnt=0;
        
        while(i<=mid && j<=high){
            if(arr[i]<=arr[j]){
                temp.emplace_back(arr[i++]);
            }else{
                cnt+=mid-i+1;
                temp.emplace_back(arr[j++]);
            }
        }
        
        while(i<=mid){
            temp.emplace_back(arr[i++]);
        }
        
        while(j<=high){
            cnt+=mid-i+1;
            temp.emplace_back(arr[j++]);
        }
        
        for(int i=0;i<temp.size();i++){
            arr[i+low]=temp[i];
        }
        return cnt;
    }
  
    int divide(int low,int high,vector<int>&arr){
        if(low>=high) return 0;
        int cnt=0;
        int mid=(low+high)/2;
        cnt+=divide(low,mid,arr);
        cnt+=divide(mid+1,high,arr);
        cnt+=merge(low,mid,high,arr);
        return cnt;
    }
    int inversionCount(vector<int> &arr) {
        // Code Here
        return divide(0,arr.size()-1,arr);
    }
};