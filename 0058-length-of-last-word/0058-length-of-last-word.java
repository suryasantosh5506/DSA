class Solution {
    public int lengthOfLastWord(String s) {
        int i=s.length()-1;
        while(s.charAt(i)==' ') i--;
        int len=0;
        for(;i>=0;i--){
            if(s.charAt(i)==' ') break;
            len++;
        }
        return len;
    }
}