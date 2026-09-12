class Solution {
public:
    int countDays(int days, vector<vector<int>>& meetings) {
        sort(meetings.begin(),meetings.end());
        vector<vector<int>>temp;
        for(auto it:meetings){
            if(temp.empty()) temp.emplace_back(it);
            else if(temp.back()[1]>=it[0]){
                temp.back()[0]=min(temp.back()[0],it[0]);
                temp.back()[1]=max(temp.back()[1],it[1]);
            }else{
                temp.emplace_back(it);
            }
        }
        int ans=temp[0][0]-1;
        int n=temp.size();
        for(int i=1;i<n;i++){
            ans+=temp[i][0]-temp[i-1][1]-1;
        }
        return ans+days-temp[n-1][1];
    }
};