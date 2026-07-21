public class Solution {
    public string RemoveOuterParentheses(string s) {
        StringBuilder ans=new StringBuilder();
        int cnt=0;
        foreach(char x in s){
            if(x=='('){
                if(cnt>0) ans.Append('(');
                cnt++;
            }else{
                cnt--;
                if(cnt>0) ans.Append(')');
            }
        }
        return ans.ToString();
    }
}