class Solution {
public:

    int n;
    vector<bool>used;
    int target;

    bool solution(int i,int tgt,int k,vector<int>&nums){
        if(k==1) return true;
        if(tgt == 0) return solution(0,target,k-1,nums);
        if(i==n || tgt<0) return false;
        
        for(int j=i;j<n;j++){
            if(j!=i && nums[j]==nums[j-1] &&!used[j-1]) continue;
            if(used[j]) continue;
            
            used[j]=true;
            if(solution(j+1,tgt-nums[j],k,nums)) return true;
            used[j]=false;
        }

        return false;
    }

    bool canPartitionKSubsets(vector<int>& nums, int k) {
        n=nums.size();
        int sum=accumulate(nums.begin(),nums.end(),0);
        if(sum%k!=0) return false;
        target=sum/k;
        used.resize(n,false);
        sort(nums.rbegin(), nums.rend());
        return solution(0,sum/k,k,nums);
    }
};