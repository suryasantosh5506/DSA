class Solution {
public:
    int jump(vector<int>& nums) {
        int i=0;
        int n=nums.size();
        int l=0,r=0;
        int steps=0;
        while(i<n-1){
            int far=0;
            for(int j=l;j<=r;j++){
                far=max(far,j+nums[j]);
            }
            l=r+1;
            r=far;
            i=r;
            steps++;
        }
        return steps;
    }
};