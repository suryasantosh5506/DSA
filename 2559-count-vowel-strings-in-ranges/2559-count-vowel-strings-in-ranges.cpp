class Solution {
public:
    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
        int n=words.size();
        vector<int>pref(n,0);
        unordered_set<char>st={'a','e','i','o','u'};
        pref[0]=(st.count(words[0][0])&&st.count(words[0][words[0].size()-1]));
        for(int i=1;i<n;i++){
            if(st.count(words[i][0])&&st.count(words[i][words[i].size()-1])){
                pref[i]=1+pref[i-1];
            }else{
                pref[i]=pref[i-1];
            }
        }

        for(int i=0;i<n;i++) cout << i << " " << pref[i] << endl;

        vector<int>ans;
        for(auto query:queries){
            if(query[0]==0) ans.emplace_back(pref[query[1]]);
            else ans.emplace_back(pref[query[1]]-pref[query[0]-1]);
        }
        return ans;
    }
};