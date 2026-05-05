class Solution {
  public:
    long subarrayXor(vector<int> &arr, int k) {
        // code here
        unordered_map<int,int>mpp;
        int xor1=0;
        mpp[0]=1;
        long cnt=0;
        for(auto x:arr){
            xor1^=x;
            cnt+=mpp[xor1^k];
            mpp[xor1]++;
        }
        return cnt;
    }
};