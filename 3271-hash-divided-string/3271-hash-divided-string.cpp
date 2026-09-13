class Solution {
public:
    string stringHash(string s, int k) {
        int n=s.size();
        string ans="";
        for(int i=0;i<n;i+=k){
            int sum=0;
            for(int j=0;j<k;j++){
                sum+=(s[i+j]-'a');
            }
            sum%=26;
            cout << sum+'a' << endl;
            ans+=sum+'a';
        }
        return ans;
    }
};