// User function Template for C++

/* Doubly linked list node class
class Node
{
public:
    int data;
    Node *next, *prev;
    Node(int val) : data(val), next(NULL), prev(NULL)
    {
    }
};
*/

class Solution {
  public:
    vector<pair<int, int>> findPairsWithGivenSum(Node *head, int target) {
        // code here
        Node* tail=head;
        vector<pair<int, int>>ans;
        for(;tail->next!=nullptr;tail=tail->next) continue;
        while(head->data<tail->data){
            int sum=head->data+tail->data;
            if(sum==target && head!=tail){
                ans.emplace_back(head->data,tail->data);
                head=head->next;
                tail=tail->prev;
            }
            else if(sum<target) head=head->next;
            else tail=tail->prev;
        }
        return ans;
    }
};