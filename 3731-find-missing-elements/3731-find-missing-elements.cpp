class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        set<int>st(nums.begin(),nums.end());
        int ele=*st.begin();
        vector<int>ans;

        while(!st.empty()){
            if(st.find(ele)==st.end()) ans.emplace_back(ele);
            else st.erase(st.find(ele));
            ele++;
        }
        return ans;
    }
};