/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     public int val;
 *     public ListNode next;
 *     public ListNode(int val=0, ListNode next=null) {
 *         this.val = val;
 *         this.next = next;
 *     }
 * }
 */
public class Solution {

    public ListNode kthNode(ListNode head,int k){
        while(head!=null && k>0){
            head=head.next;
            k--;
        }
        return head;
    }

    public ListNode reverse(ListNode head){
        ListNode prev=null,curr=head;
        while(curr!=null){
            ListNode next=curr.next;
            curr.next=prev;
            prev=curr;
            curr=next;
        }
        return prev;
    }

    public ListNode ReverseKGroup(ListNode head, int k) {
        ListNode temp=head;
        ListNode prevNode=null,nextNode=null;

        while(temp!=null){
            ListNode knode=kthNode(temp,k-1);
            if(knode==null){
                if(prevNode!=null) prevNode.next=temp;
                break;
            }
            nextNode=knode.next;
            knode.next=null;
            ListNode rev=reverse(temp);
            if(temp==head) head=knode;
            if(prevNode!=null) prevNode.next=rev;
            prevNode=temp;
            temp=nextNode;
        }
        return head;
    }
}