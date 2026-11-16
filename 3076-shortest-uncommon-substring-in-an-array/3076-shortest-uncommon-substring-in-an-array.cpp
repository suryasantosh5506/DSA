class Solution {
public:
    vector<string> shortestSubstrings(vector<string>& arr) {
        unordered_map<string,int>mpp;
        int n=arr.size();
        for(string &s:arr){
            int n=s.size();
            unordered_set<string>st;
            for(int i=0;i<n;i++){
                for(int j=i;j<n;j++){
                    st.insert(s.substr(i,j-i+1));
                }
            }
            for(string x:st) mpp[x]++;
        }
        vector<string>ans;
        for(string &s:arr){
            string temp="";
            int n=s.size();
            for(int i=0;i<n;i++){
                for(int j=i;j<n;j++){
                    string sub=s.substr(i,j-i+1);
                    if(mpp.count(sub)){
                        if(mpp[sub]>1) continue;
                        if(temp.empty() || sub.size()<temp.size()) temp=sub;
                        else if(temp.size()==sub.size() && sub<temp) temp=sub;
                    }
                }
            }
            ans.emplace_back(temp);
        }
        return ans;
    }
};