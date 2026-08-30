class Solution {
public:
    int minDeletion(vector<int>& nums) {
        int index=0;
        int n=nums.size();
        stack<int>st;
        for(int &x:nums){
            if(index%2==0){
                st.push(x);
            }else{
                if(!st.empty() && st.top()==x){
                    continue;
                }
                st.push(x);
            }
            index++;
        }
        if(index%2==1) st.pop();
        return n-st.size();
    }
};