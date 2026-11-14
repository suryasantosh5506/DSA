class Solution {
public:
    string lexSmallest(string s) {
        int n=s.size();
        string ans=s;
        for(int i=0;i<n;i++){
            string temp=s;
            reverse(temp.begin(),temp.begin()+i+1);
            ans=min(ans,temp);
        }
        for(int i=n-1;i>=0;i--){
            string temp=s;
            reverse(temp.begin()+i,temp.end());
            ans=min(ans,temp);
        }
        return ans;
    }
};