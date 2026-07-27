class Solution {
public:
    int findMinDifference(vector<string>& timePoints) {
        vector<int>minutes;
        for(string &x:timePoints){
            int hours=stoi(x.substr(0,2));
            int minute=stoi(x.substr(3));
            minutes.emplace_back(hours*60+minute);
        }
        sort(minutes.begin(),minutes.end());
        int mini=INT_MAX;
        int n=timePoints.size();
        for(int i=1;i<n;i++){
            mini=min(mini,minutes[i]-minutes[i-1]);
        }
        mini = min(mini, 1440 - minutes.back() + minutes.front());
        return mini;
    }
};