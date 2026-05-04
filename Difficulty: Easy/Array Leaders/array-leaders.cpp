

class Solution {
  public:
    vector<int> leaders(vector<int>& arr) {
        // code here
        vector<int>ans;
        int n=arr.size();
        int maxi=arr[n-1];
        
        for(int i=n-1;i>=0;i--){
            if(arr[i]>=maxi){
                ans.emplace_back(arr[i]);
                maxi=arr[i];
            }
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};