class Solution {
    public int numberOfSpecialChars(String word) {
        int lastSmall[]=new int[26];
        int firstUpper[]=new int[26];
        int n=word.length();

        for(int i=0;i<26;i++){
            firstUpper[i]=-1;
            lastSmall[i]=-1;
        }

        for(int i=0;i<n;i++){
            char ch=word.charAt(i);
            if(Character.isLowerCase(ch)) lastSmall[ch-'a']=i;
            else{
                if(firstUpper[ch-'A']==-1){
                    firstUpper[ch-'A']=i;
                }
            }
        }

        int ans=0;

        for(int i=0;i<26;i++){
            if(lastSmall[i]!=-1 && firstUpper[i]!=-1 && lastSmall[i]<firstUpper[i]){
                ans++;
            }
        }
        return ans;
    }
}