class Solution {
public:
    string compressedString(string word) {
        string comp="";
        int n=word.size();
        for(int i=0;i<n;){
            char req=word[i];
            int cnt=1;
            for(int j=1;j<9 && i+j<n ;j++){
                if(word[i+j]==req) cnt++;
                else break;
            }
            comp+=to_string(cnt)+req;
            i+=cnt;
        }
        return comp;
    }
};