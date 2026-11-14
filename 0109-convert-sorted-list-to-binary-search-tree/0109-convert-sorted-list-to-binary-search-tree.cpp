/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
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

    vector<int>arr;
    int n;

    TreeNode* solution(int low,int high){
        if(low>high) return nullptr;
        if(low==high) return new TreeNode(arr[low]);
        int mid=low+(high-low)/2;
        TreeNode* root=new TreeNode(arr[mid]);
        root->left=solution(low,mid-1);
        root->right=solution(mid+1,high);
        return root;
    }

    TreeNode* sortedListToBST(ListNode* head) {
        for(ListNode* temp=head;temp;temp=temp->next) arr.emplace_back(temp->val);
        n=arr.size();
        return solution(0,n-1);
    }
};