class Solution {
public:

    int maxi=0;
    int cnt=0;

    void solution(int i,int curror,vector<int>&nums){
        if(i==nums.size()){  
            if(curror>maxi){
                maxi=curror;
                cnt=1;
            }else if(curror==maxi) cnt++;

            return;
        }

        solution(i+1,curror|nums[i],nums);
        solution(i+1,curror,nums);
    }

    int countMaxOrSubsets(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>>ans;
        vector<int>seq;
        solution(0,0,nums);
        return cnt;
    }
};