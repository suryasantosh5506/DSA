class Solution {
  public:
    vector<int> getDivisors(int n) {
        // code here
        vector<int>ans;
        for(int i=1;i*i<=n;i++){
            if(n%i==0){
                ans.emplace_back(i);
                int other=n/i;
                if(other!=i){
                  ans.emplace_back(other);  
                }
            }
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};