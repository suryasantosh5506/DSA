class Solution {
public:
    vector<int> numberOfLines(vector<int>& widths, string s) {
        int line=1;
        int sum=0;
        for(auto x:s){
            if(sum+widths[x-'a']>100){
                line++;
                sum=0;
            }
            sum+=widths[x-'a'];
        }
        return {line,sum};
    }
};