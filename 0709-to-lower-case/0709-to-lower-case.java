class Solution {
    public String toLowerCase(String s) {
        StringBuilder ans=new StringBuilder();

        for(char x:s.toCharArray()){
            ans.append(Character.toLowerCase(x));
        }
        return ans.toString();
    }
}