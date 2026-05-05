class Solution {
public:
    int countDistinct(vector<int>& nums, int k, int p) {
        int n=nums.size();
        set<vector<int>>st;

        for(int i=0;i<n;i++){
            int cnt=0;
            vector<int>arr;
            for(int j=i;j<n;j++){
                if(nums[j]%p==0){
                    cnt++;
                }

                if(cnt>k) break;
                arr.emplace_back(nums[j]);
                st.insert(arr);
            }
        }

        return st.size();
    }
};