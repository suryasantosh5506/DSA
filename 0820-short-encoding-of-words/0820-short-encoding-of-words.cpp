class Solution {
public:
    int minimumLengthEncoding(vector<string>& words) {
        int ans=0;
        unordered_set<string>st(words.begin(), words.end());
        vector<string>arr;
        for(string x:st) arr.emplace_back(x);
        int n=arr.size();
        for(int i=0;i<n;i++){
            bool suffix=false;
            for(int j=0;j<n;j++){
                if(j==i) continue;
                int f=arr[i].size();
                int s=arr[j].size();
                if(f<=s && arr[j].substr(s-f)==arr[i]){
                    suffix=true;
                    break;
                }
            }
            if(!suffix) ans+=arr[i].size()+1;
        }
        return ans;
    }
};