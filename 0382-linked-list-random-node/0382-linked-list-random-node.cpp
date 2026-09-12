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

    vector<int>arr;
    int n;

    Solution(ListNode* head) {
        for(ListNode* temp=head;temp!=nullptr;temp=temp->next) arr.emplace_back(temp->val);
        n=arr.size();
    }
    
    int getRandom() {
        return arr[rand()%arr.size()];
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(head);
 * int param_1 = obj->getRandom();
 */