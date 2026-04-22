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
    ListNode* insertionSortList(ListNode* head) {
        vector<ListNode*>arr;
        while(head!=nullptr){
            arr.emplace_back(head);
            head=head->next;
        }

        int n=arr.size();

        for(int i=0;i<n;i++){
            int j=i;
            while(j>0 && arr[j]->val<arr[j-1]->val){
                swap(arr[j],arr[j-1]);
                j--;
            }
        }

        head=arr[0];
        ListNode* dummy=head;
        for(int i=1;i<n;i++){
            dummy->next=arr[i];
            dummy=dummy->next;
        }
        dummy->next=nullptr;
        return head;
    }
};