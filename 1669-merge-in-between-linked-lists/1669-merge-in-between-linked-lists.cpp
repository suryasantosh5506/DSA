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
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        ListNode* first=nullptr,*second=nullptr;
        ListNode* temp=list1;
        int cnt=a;
        while(cnt>1){
            cnt--;
            temp=temp->next;
        }
        first=temp;
        cnt=b;
        temp=list1;
        while(cnt>=0){
            cnt--;
            temp=temp->next;
        }
        second=temp;
        ListNode* tail=list2;
        for(;tail->next!=nullptr;tail=tail->next);
        if(a==1){
            list1->next=list2;
            tail->next=second;

            return list1;
        }
        first->next=list2;
        if(tail) tail->next=second;
        return list1;
    }
};