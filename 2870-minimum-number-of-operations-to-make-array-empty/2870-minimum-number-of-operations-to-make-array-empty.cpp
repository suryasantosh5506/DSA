class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n=nums.size();
        unordered_map<int,int>mpp;
        for(int &x:nums) mpp[x]++;
        int ans=0;
        for(auto it:mpp){
            int freq=it.second;
            if(freq==1) return -1;
            int op=0;
            if(freq%3==0) op=freq/3;
            else{
                op+=freq/3;
                freq%=3;
                
                if(freq=2){
                    op++;
                }else if(freq==1){
                    op--;
                    op+=2;
                }
            }
            ans+=op;
        }
        return ans;
    }
};