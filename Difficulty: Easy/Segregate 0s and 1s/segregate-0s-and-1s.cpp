class Solution {
  public:
    void segregate0and1(vector<int> &arr) {
        // code here
        int j=0;
        int n=arr.size();
        for(;j<n;j++){
            if(arr[j]==1) break;
        }
        
        for(int i=j;i<n;i++){
            if(arr[i]!=1){
                swap(arr[i],arr[j]);
                j++;
            }
        }
        
    }
};