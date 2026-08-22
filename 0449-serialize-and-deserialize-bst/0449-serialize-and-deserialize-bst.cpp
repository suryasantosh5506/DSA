/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string data="";
        if(!root) return data;
        data+=to_string(root->val)+',';
        queue<TreeNode*>q;
        q.push(root);

        while(!q.empty()){
            auto top=q.front();
            q.pop();

            if(top->left){
                q.push(top->left);
                data+=to_string(top->left->val)+',';
            }else{
                data+="#,";
            }

            if(top->right){
                q.push(top->right);
                data+=to_string(top->right->val)+',';
            }else{
                data+="#,";
            }
        }
        return data;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data.empty()) return nullptr;
        stringstream ss(data);
        string val="";
        getline(ss,val,',');
        TreeNode* root=new TreeNode(stoi(val));
        queue<TreeNode*>q;
        q.push(root);

        while(!q.empty()){
            auto top=q.front();
            q.pop();

            if(!getline(ss,val,',')) break;

            if(val!="#"){
                top->left=new TreeNode(stoi(val));
                q.push(top->left);
            }

            if(!getline(ss,val,',')) break;

            if(val!="#"){
                top->right=new TreeNode(stoi(val));
                q.push(top->right);
            }
        }
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec* ser = new Codec();
// Codec* deser = new Codec();
// string tree = ser->serialize(root);
// TreeNode* ans = deser->deserialize(tree);
// return ans;