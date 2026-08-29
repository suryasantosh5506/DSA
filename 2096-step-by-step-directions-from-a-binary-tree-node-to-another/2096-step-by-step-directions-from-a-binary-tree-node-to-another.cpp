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

    unordered_map<TreeNode*,TreeNode*>parents;
    TreeNode* target;
    string ans="";
    unordered_set<TreeNode*>visited;

    void markparents(TreeNode* root,int src){
        if(!root) return;
        queue<TreeNode*>q;
        q.push(root);
        
        while(!q.empty()){
            auto top=q.front();
            q.pop();

            if(top->val==src) target=top;

            if(top->left){
                q.push(top->left);
                parents[top->left]=top;
            }

            if(top->right){
                q.push(top->right);
                parents[top->right]=top;
            }
        }
    }

    bool solution(TreeNode* root,string &seq,int target){
        if(!root) return false;
        if(root->val==target){
            ans=seq;
            return true;
        }

        if(parents.count(root) && !visited.count(parents[root])){
            visited.insert(parents[root]);
            seq+='U';
            if(solution(parents[root],seq,target)){
                return true;
            }
            seq.pop_back();
        }

        if(root->left && !visited.count(root->left)){
            visited.insert(root->left);
            seq+='L';
            if(solution(root->left,seq,target)){
                return true;
            }
            seq.pop_back();
        }

        if(root->right && !visited.count(root->right)){
            visited.insert(root->right);
            seq+='R';
            if(solution(root->right,seq,target)){
                return true;
            }
            seq.pop_back();
        }

        return false;
    }

    string getDirections(TreeNode* root, int startValue, int destValue) {
        markparents(root,startValue);
        if(!root || !target) return ans;
        visited.insert(target);
        string seq="";
        solution(target,seq,destValue);
        return ans;
    }
};