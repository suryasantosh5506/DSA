class Solution {
  public:
    int minPlatform(vector<int>& arr, vector<int>& dep) {
        // code here
        sort(arr.begin(),arr.end());
        sort(dep.begin(),dep.end());
        
        int i=0,j=0;
        int n=arr.size();
        int platforms=0;
        int maxi=0;   
        
        while(i<n && j<n){
            if(arr[i]>dep[j]){
                platforms--;
                j++;
            }else{
                platforms++;
                i++;
                maxi=max(maxi,platforms);
            }
        }
        return maxi;
    }
};
