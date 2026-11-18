class Solution {
public:

    int n;
    vector<bool>visited;
    int best=-1;

    bool validhour(int hour){
        return hour>=0 && hour<=23;
    }

    bool validmin(int minutes){
        return minutes>=0 && minutes<=59;
    }

    void solution(int i,int hr,int mn,vector<int>& arr){
        if(i==4){
            if(validhour(hr) && validmin(hr)) best=max(best,hr*60+mn);
            return;
        }
        
        for(int j=0;j<n;j++){
            if(visited[j]) continue;
            visited[j]=true;
            if (i<2) {
                int newh=hr*10+arr[j];
                if(validhour(newh)) solution(i+1,newh,mn,arr);
            }else {
                int newmin=mn*10+arr[j];
                if(validmin(newmin)) solution(i+1,hr,newmin,arr);
            }
            visited[j]=false;
        }
    }

    string largestTimeFromDigits(vector<int>& arr) {
        n=arr.size();
        visited.assign(n,false);
        solution(0,0,0,arr);
        if (best == -1) return "";

        int hour = best / 60;
        int min = best % 60;

        string ans = "";

        if (hour < 10) ans += "0";
        ans += to_string(hour);

        ans += ":";

        if (min < 10) ans += "0";
        ans += to_string(min);

        return ans;
    }
};