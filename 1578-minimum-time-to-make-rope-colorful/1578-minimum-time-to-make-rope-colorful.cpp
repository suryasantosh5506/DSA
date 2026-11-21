class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        stack<pair<char,int>>st;
        int n=colors.size();
        int ans=0;
        for(int i=0;i<n;i++){
            if(!st.empty() && st.top().first==colors[i]){
                auto [color,cost]=st.top();
                st.pop();
                if(cost<neededTime[i]) st.push({color,neededTime[i]});
                else st.push({color,cost});
                ans+=min(cost,neededTime[i]);
            }else{
                st.push({colors[i],neededTime[i]});
            }
        }
        return ans;
    }
};