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
class CBTInserter {
public:

    queue<TreeNode*>q;
    TreeNode* root=nullptr;

    void init(TreeNode* root){
        this->root=root;
        vector<TreeNode*>temp;
        q.push(root);
        while(!q.empty()){
            int size=q.size();

            for(int i=0;i<size;i++){
                auto top=q.front();
                q.pop();
                temp.emplace_back(top);
                
                if(top->left) q.push(top->left);
                if(top->right) q.push(top->right);
            }
        }

        for(auto it:temp){
            if(it->left && it->right) continue;
            q.push(it);
        }
    }

    CBTInserter(TreeNode* root) {
        init(root);
    }
    
    int insert(int val) {
        int v=q.front()->val;
        TreeNode* nnode=new TreeNode(val);
        if(!q.front()->left){
            q.front()->left=nnode;
        }else{
            q.front()->right=nnode;
            q.pop();
        }
        q.push(nnode);
        return v;
    }
    
    TreeNode* get_root() {
        return root;
    }
};

/**
 * Your CBTInserter object will be instantiated and called as such:
 * CBTInserter* obj = new CBTInserter(root);
 * int param_1 = obj->insert(val);
 * TreeNode* param_2 = obj->get_root();
 */