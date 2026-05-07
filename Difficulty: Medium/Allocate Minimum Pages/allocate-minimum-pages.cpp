class Solution {
  public:
  
    bool possible(int mid,vector<int> &arr, int k){
        int students=1;
        int pages=0;
        for(auto x:arr){
            if(pages+x>mid){
                students++;
                pages=0;
            }
                pages+=x;
            
            if(students>k) return false;
        }
        return true;
    }
  
    int findPages(vector<int> &arr, int k) {
        int n=arr.size();
        if(k>n) return -1;
        // code here
        int low=*max_element(arr.begin(),arr.end());
        int high=accumulate(arr.begin(),arr.end(),0);
        int ans=0;
        
        while(low<=high){
            int mid=low+(high-low)/2;
            if(possible(mid,arr,k)){
                ans=mid;
                high=mid-1;
            }
            else low=mid+1;
        }
        return ans;
    }
};