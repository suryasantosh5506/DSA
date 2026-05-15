
class Solution {
  public:

    void merge(int low,int mid,int high,vector<pair<int,int>>&arr,vector<int>&count){
        int i=low,j=mid+1;
        vector<pair<int,int>>temp;
        while(i<=mid && j<=high){
            if(arr[i].first<arr[j].first){
                count[arr[i].second]+=high-j+1;
                temp.emplace_back(arr[i++]);
            }else{
                temp.emplace_back(arr[j++]);
            }
        }
        
        while(i<=mid){
            count[arr[i].second]+=high-j+1;
            temp.emplace_back(arr[i++]);
        }
        
        while(j<=high){
            temp.emplace_back(arr[j++]);
        }
        
        for(int i=0;i<temp.size();i++){
            arr[i+low]=temp[i];
        }
    }

    void divide(int low,int high,vector<pair<int,int>>&arr,vector<int>&count){
        if(low>=high) return;
        int mid=low+(high-low)/2;
        divide(low,mid,arr,count);
        divide(mid+1,high,arr,count);
        merge(low,mid,high,arr,count);
    }

    vector<int> count_NGE(vector<int> &arr, vector<int> &indices) {
        // code here
        vector<pair<int,int>>nums;
        int n=arr.size();
        for(int i=0;i<n;i++){
            nums.emplace_back(arr[i],i);
        }
        vector<int>count(n);
        divide(0,n-1,nums,count);
        vector<int>ans;
        for(auto x:indices){
            ans.emplace_back(count[x]);
        }
        return ans;
    }
};