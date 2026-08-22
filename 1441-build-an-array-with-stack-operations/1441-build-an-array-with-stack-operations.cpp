class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
        vector<string>ans;
        unordered_set<int>st(target.begin(),target.end());

        for(int i=1;i<=n;i++){
            if(st.count(i)){
                ans.emplace_back("Push");
            }else{
                int ele=i;
                while(ele<=n){
                    if(st.count(ele)){
                        ans.emplace_back("Push");
                        ans.emplace_back("Pop");
                        break;
                    }
                    ele++;
                }
            }
        }
        return ans;
    }
};