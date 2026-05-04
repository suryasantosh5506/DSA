class Solution {

    List<Integer> solution(int row){
        int ele=1;
        List<Integer>ans=new ArrayList<>();
        ans.add(ele);

        for(int i=0;i<row;i++){
            ele*=(row-i);
            ele/=(i+1);
            ans.add(ele);
        }
        return ans;
    }

    public List<List<Integer>> generate(int numRows) {
        List<List<Integer>>ans=new ArrayList<>();
        for(int i=0;i<numRows;i++){
            ans.add(solution(i));
        }
        return ans;
    }
}