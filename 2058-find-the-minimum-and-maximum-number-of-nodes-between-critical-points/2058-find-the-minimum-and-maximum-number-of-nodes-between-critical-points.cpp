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

    ListNode* reverse(ListNode* head){
        ListNode* prev=nullptr,*next=nullptr,*curr=head;
        while(curr){
            next=curr->next;
            curr->next=prev;
            prev=curr;
            curr=next;
        }
        return head;
    }

    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        if(!head || !head->next) return {-1,-1};
        int firstminima=-1,firstmaxima=-1;
        int secondminima=-1,secondmaxima=-1;
        int prev=head->val;
        int prevcritical=-1;
        int mini=INT_MAX;
        int cnt=1;
        for(ListNode* temp=head->next;temp->next!=nullptr;temp=temp->next,cnt++){
            if(temp->val < temp->next->val && temp->val<prev){
                if(firstminima==-1) firstminima=cnt;
                else secondminima=cnt;
                if(prevcritical!=-1) mini=min(mini,cnt-prevcritical);
                prevcritical=cnt;
            }
            if(temp->val > temp->next->val && temp->val>prev){
                if(firstmaxima==-1) firstmaxima=cnt;
                else secondmaxima=cnt;
                if(prevcritical!=-1) mini=min(mini,cnt-prevcritical);
                prevcritical=cnt;
            }
            prev=temp->val;
        }
        if(prevcritical == -1 || mini == INT_MAX) return {-1,-1};
        int first = INT_MAX;
        int last = -1;

        if(firstminima != -1){
            first = min(first, firstminima);
            last = max(last, secondminima != -1 ? secondminima : firstminima);
        }

        if(firstmaxima != -1){
            first = min(first, firstmaxima);
            last = max(last, secondmaxima != -1 ? secondmaxima : firstmaxima);
        }

        return {mini, last-first};
    }
};