class Solution {
public:
    string arrangeWords(string text) {
        vector<pair<string,int>>arr;
        // {str,ind}
        stringstream ss(text);
        string word="";
        int i=0;
        while(getline(ss,word,' ')){
            word[0]=tolower(word[0]);
            arr.emplace_back(word,i++);
        }
        sort(arr.begin(),arr.end(),[&](auto &a,auto &b){
            if(a.first.size()==b.first.size()) return a.second<b.second;
            return a.first.size()<b.first.size();
        });
        string ans="";
        for(auto it:arr){
            string word=it.first;
            if(ans.empty()) word[0]=toupper(word[0]);
            ans+=word+" ";
        }
        if(!ans.empty()) ans.pop_back();
        return ans;
    }
};