class Solution {
    public int numberOfSpecialChars(String word) {
        Set<Character>upper=new HashSet<>();
        Set<Character>lower=new HashSet<>();
        int cnt=0;

        for(char ch:word.toCharArray()){
            if(Character.isUpperCase(ch)) upper.add(Character.toLowerCase(ch));
            else lower.add(ch);
        }

        for(char ch:lower){
            if(upper.contains(ch)) cnt++;
        }
        return cnt;
    }
}