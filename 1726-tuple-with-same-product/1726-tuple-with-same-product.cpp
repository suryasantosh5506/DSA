class Solution {
public:
    int tupleSameProduct(vector<int>& nums) {
        unordered_map<int,int>mpp;
        int cnt=0;
        int n=nums.size();
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                int prod=nums[i]*nums[j];
                // there are 8 ways to arrange 4 numbers
                cnt+=8*mpp[prod];
                mpp[prod]++;
            }
        }
        return cnt;
    }
};