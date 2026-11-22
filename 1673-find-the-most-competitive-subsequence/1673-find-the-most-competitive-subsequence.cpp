class Solution {
public:
    vector<int> mostCompetitive(vector<int>& nums, int k) {
        vector<int>st;
        int n=nums.size();
        for(int i=0;i<n;i++){
            int x=nums[i];
            while(!st.empty() && st.back()>x && st.size()-1+(n-i)>=k) st.pop_back();
            st.emplace_back(x);
        }
        return vector<int>(st.begin(),st.begin()+k);
    }
};