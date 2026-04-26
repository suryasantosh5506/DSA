class Solution {
    public boolean validDigit(int n, int x) {
        String num=Integer.toString(n);
        return num.charAt(0)!=(x+'0') && num.contains(Character.toString(x+'0'))==true;
    }
}