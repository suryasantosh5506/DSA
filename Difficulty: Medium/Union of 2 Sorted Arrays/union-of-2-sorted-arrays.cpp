class Solution {
  public:
    vector<int> findUnion(vector<int> &a, vector<int> &b) {
        // code here
        int n=a.size();
        int m=b.size();
        vector<int>ans;
        int i=0,j=0;
        while(i<n&&j<m){
            if(a[i]==b[j]){
                if(ans.empty()||ans.back()!=a[i]){
                    ans.emplace_back(a[i]);
                }
                i++;
                j++;
            }
            else if(a[i]<b[j]){
                if(ans.empty() || ans.back()!=a[i]){
                    ans.emplace_back(a[i]);
                } 
                i++;
            }
            else{
                if(ans.empty() || ans.back()!=b[j]){
                    ans.emplace_back(b[j]);
                }
                j++;
            }
        }
        
        while(i<n){
            if(ans.empty()||ans.back()!=a[i]){
                ans.emplace_back(a[i]);
            }
            i++;
        }
        
        while(j<m){
            if(ans.empty()||ans.back()!=b[j]){
                ans.emplace_back(b[j]);
            }
            j++;
        }
        
        return ans;
    }
};