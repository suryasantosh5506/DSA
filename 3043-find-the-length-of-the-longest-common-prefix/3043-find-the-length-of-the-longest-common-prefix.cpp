class Solution {
public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        unordered_set<string>st;
        int ans=0;

        for(auto x:arr1){
            string str=to_string(x);
            string pref="";
            for(auto ch:str){
                pref+=ch;
                st.insert(pref);
            }
        }

        for(auto x:arr2){
            string str=to_string(x);
            string pref="";
            for(auto ch:str){
                pref+=ch;
                if(st.find(pref)!=st.end()){
                    ans=max(ans,(int)pref.size());
                }
            }
        }
        return ans;
    }
};