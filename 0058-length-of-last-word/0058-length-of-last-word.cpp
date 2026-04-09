class Solution {
public:
    int lengthOfLastWord(string s) {
        int n=s.size();
        int i=n-1;
        while(s[i]==' '){
            i--;
        }
        cout << i << endl;
        int len=0;
        for(;i>=0;i--){
            if(s[i]==' ')break;
            len++;
        }
        return len;
    }
};