class Solution {
public:

    vector<vector<int>>ans;
    vector<int>seq;
    int n;

    void solution(int i,vector<int>&arr){
        ans.emplace_back(seq);
        if(i==n) return;

        for(int j=i;j<n;j++){
            if(j!=i && arr[j]==arr[j-1]) continue;
            seq.emplace_back(arr[j]);
            solution(j+1,arr);
            seq.pop_back();
        }
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        n=nums.size();
        solution(0,nums);
        return ans;
    }
};