class Solution {
public:
    vector<string> reorderLogFiles(vector<string>& logs) {
        vector<vector<string>>logdata;
        vector<string>digits;
        // {logidentifier,data}
        for(string &log:logs){
            stringstream ss(log);
            string identifier="";
            getline(ss,identifier,' ');
            string nextword;
            getline(ss,nextword,' ');
            if(!isdigit(nextword[0])) logdata.push_back({identifier,log});
            else digits.emplace_back(log);
        }
        sort(logdata.begin(),logdata.end(),[&](auto &a,auto &b){
            string contentA=a[1].substr(a[0].size()+1);
            string contentB=b[1].substr(b[0].size()+1);

            if(contentA==contentB) return a[0]<b[0];
            return contentA<contentB;
        });
        vector<string>ans;
        for(auto x:logdata) ans.emplace_back(x[1]);
        for(auto x:digits) ans.emplace_back(x);
        return ans;
    }
};