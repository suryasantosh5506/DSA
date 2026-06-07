/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */
class Solution {
    public TreeNode createBinaryTree(int[][] descriptions) {
        Map<Integer,TreeNode>mpp=new HashMap<>();
        Set<Integer> children=new HashSet<>();
        for(int node[]:descriptions){
            int parent=node[0];
            int value=node[1];
            int isleft=node[2];
            children.add(value);

            if(mpp.containsKey(parent)){
                if(mpp.containsKey(value)){
                    if(isleft==1) mpp.get(parent).left=mpp.get(value);
                    else mpp.get(parent).right=mpp.get(value);
                }else{
                    TreeNode temp=new TreeNode(value);
                    if(isleft==1) mpp.get(parent).left=temp;
                    else mpp.get(parent).right=temp;
                    mpp.put(value,temp);
                }
            }else{
                TreeNode parentNode=new TreeNode(parent);
                mpp.put(parent,parentNode);
                if(mpp.containsKey(value)){
                    if(isleft==1) mpp.get(parent).left=mpp.get(value);
                    else mpp.get(parent).right=mpp.get(value);
                }else{
                    TreeNode temp=new TreeNode(value);
                    if(isleft==1) mpp.get(parent).left=temp;
                    else mpp.get(parent).right=temp;
                    mpp.put(value,temp);
                }
            }
        }

        for(int it:mpp.keySet()){
            if(!children.contains(it)) return mpp.get(it);
        }
        return null;
    }
}