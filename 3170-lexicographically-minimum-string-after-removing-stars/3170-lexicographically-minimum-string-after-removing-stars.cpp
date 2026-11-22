class Solution {
public:
    string clearStars(string s) {
        priority_queue<pair<char,int>,vector<pair<char,int>>,greater<pair<char,int>>>pq;
        unordered_set<int>deleted;
        int n=s.size();
        for(int i=0;i<n;i++){
            if(s[i]=='*'){
                auto [ch,ind]=pq.top();
                pq.pop();
                deleted.insert(abs(ind));
            }else{
                pq.push({s[i],-i});
            }
        }
        string ans="";
        for(int i=0;i<n;i++) if(s[i]!='*' && !deleted.count(i)) ans+=s[i];
        return ans;
    }
};