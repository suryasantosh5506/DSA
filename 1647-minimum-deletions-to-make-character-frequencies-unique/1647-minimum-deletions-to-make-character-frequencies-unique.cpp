class Solution {
public:
    int minDeletions(string s) {
        unordered_map<char,int>mpp;
        for(char &x:s){
            mpp[x]++;
        }
        unordered_map<int,int>freq;
        vector<pair<int,char>>arr;
        for(auto it:mpp){
            freq[it.second]++;
            arr.emplace_back(it.second,it.first);
        }
        sort(arr.rbegin(),arr.rend());

        int ans=0;
        for(auto x:arr){
            if(freq[x.first]==1) continue;
            int cnt=x.first;
            while(cnt>0 && freq.count(cnt)) cnt--;
            ans+=x.first-cnt;
            freq[x.first]--;
            freq[cnt]=1;
        }
        return ans;
    }
};