class Solution {
public:
    int longestBeautifulSubstring(string word) {
        int n=word.size();
        int ans=0;
        for(int i=0;i<n;){
            if(word[i]=='a'){
                char prev='a';
                int j=i+1;
                for(;j<n;j++){
                    if (prev=='a' && word[j]!='a' && word[j]!='e') break;
                    else if(prev=='e' && word[j]!='e' && word[j]!='i') break;
                    else if(prev=='i' && word[j]!='i' && word[j]!='o') break;
                    else if(prev=='o' && word[j]!='o' && word[j]!='u') break;
                    else if(prev=='u' && word[j]!='u') break;
                    prev=word[j];
                }
                if(prev=='u') ans=max(ans,j-i);
                i=j;
            }else i++;
        }
        return ans;
    }
};