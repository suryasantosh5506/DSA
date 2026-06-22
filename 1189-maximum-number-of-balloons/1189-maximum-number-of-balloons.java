class Solution {
    public int maxNumberOfBalloons(String text) {
        int b=0,a=0,l=0,o=0,n=0;
        for(char x:text.toCharArray()){
            if(x=='b') b++;
            if(x=='a') a++;
            if(x=='l') l++;
            if(x=='o') o++;
            if(x=='n') n++;
        }
        l/=2;
        o/=2;
        return Math.min(b,Math.min(a,Math.min(l,Math.min(o,n))));
    }
}