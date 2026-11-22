class Solution {
public:
    vector<string> assignUmbrella(vector<int>& rain) {
        vector<string>ans;
        int n=rain.size();
        bool available=true;
        int a=0,b=0;
        for(int i=0;i<n;i++){
            bool alice=(i+1<n && rain[i]==1 && rain[i+1]==1);
            bool bob=(rain[i]==1);
            if(alice && bob){
                if(b<a){
                    b++;
                    ans.emplace_back("Bob");
                }else{
                    a++;
                    ans.emplace_back("Alice");
                }
            }else if(alice){
                a++;
                ans.emplace_back("Alice");
            }else if(bob){
                b++;
                ans.emplace_back("Bob");
            }else ans.emplace_back("None");
        }   
        return ans;
    }
};