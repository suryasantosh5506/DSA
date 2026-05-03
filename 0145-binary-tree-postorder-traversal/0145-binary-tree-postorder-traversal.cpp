/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int>ans;
        stack<TreeNode*>st;

        while(!st.empty() || root!=nullptr){
            if(root!=nullptr){
                st.push(root);
                root=root->left;
            }else{
                TreeNode* top=st.top()->right;

                if(top==nullptr){
                    top=st.top();
                    st.pop();
                    ans.emplace_back(top->val);

                    while(!st.empty() && top==st.top()->right){
                        top=st.top();
                        st.pop();
                        ans.emplace_back(top->val);
                    }
                }else{
                    root=top;
                }
            }
        }
        return ans;
    }
};