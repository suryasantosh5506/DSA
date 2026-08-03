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

    priority_queue<pair<int,ListNode*>,vector<pair<int,ListNode*>>,greater<pair<int,ListNode*>>>pq;

    void insert(ListNode* head){
        for(ListNode* node=head;node!=nullptr;node=node->next){
            pq.push({node->val,node});
        }
    }

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        for(ListNode* temp:lists){
            insert(temp);
        }
        ListNode* dummy=new ListNode(-1);
        ListNode* temp=dummy;

        while(!pq.empty()){
            temp->next=pq.top().second;
            pq.pop();
            temp=temp->next;
        }
        return dummy->next;
    }
};