class Solution {
    public int furthestDistanceFromOrigin(String moves) {
         int l=0,r=0,dash=0;
        for(char x:moves.toCharArray()){
            if(x=='L') l++;
            else if(x=='R') r++;
            else dash++;
        }
        return dash+Math.max(l,r)-Math.min(l,r);
    }
}