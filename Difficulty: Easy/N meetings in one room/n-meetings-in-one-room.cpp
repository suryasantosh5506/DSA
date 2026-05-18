class Solution {
  public:
    // Function to find the maximum number of meetings that can
    // be performed in a meeting room.
    int maxMeetings(vector<int>& start, vector<int>& end) {
        // Your code here
        int n=start.size();
        vector<pair<int,int>>arr;
        for(int i=0;i<n;i++) arr.emplace_back(start[i],end[i]);
        sort(arr.begin(),arr.end(),[](auto a,auto b){
            return a.second<b.second;
        });
        
        int cnt=0;
        int last=-1;
        for(auto x:arr){
            if(last==-1 || x.first>last){
                cnt++;
                last=x.second;
            }
        }
        return cnt;
    }
};