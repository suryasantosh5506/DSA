class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        set<int>st(nums.begin(),nums.end());

        int ans=0;
        for(auto it:st){
            if(st.count(it-1)) continue;
            int ele=it;
            int cnt=0;
            while(st.count(ele)){
                cnt++;
                ele++;
            }
            ans=max(ans,cnt);
        }
        return ans;
    }
};