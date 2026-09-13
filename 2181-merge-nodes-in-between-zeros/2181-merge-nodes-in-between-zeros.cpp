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
class Solution {
public:
    ListNode* mergeNodes(ListNode* head) {
        ListNode* dummy=new ListNode(-1);
        ListNode* temp=dummy;
        int sum=0;
        for(ListNode* tem=head->next;tem!=nullptr;tem=tem->next){
            sum+=tem->val;
            if(tem->val==0 && sum!=0){
                temp->next=new ListNode(sum);
                sum=0;
                temp=temp->next;
            }
        }
        return dummy->next;
    }
};