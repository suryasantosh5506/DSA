class Solution {
  public:
    vector<string> graycode(int n) {
        // code here
        int total=1<<n;
        vector<string>ans;
        
        for(int i=0;i<total;i++){
            string seq;
            int gray = i ^ (i >> 1);
            for(int j=n-1;j>=0;j--){
                seq+=((gray >> j) & 1) ? '1' : '0';
            }
            ans.emplace_back(seq);
        }
        return ans;
    }
};      