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

    public ListNode middleNode(ListNode head){
        if(head==null || head.next==null) return head;
        ListNode slow=head,fast=head.next;
        while(fast!=null && fast.next!=null){
            slow=slow.next;
            fast=fast.next.next;
        }
        return slow;
    }

    public ListNode merge(ListNode h1,ListNode h2){
        ListNode dummy=new ListNode(-1);
        ListNode temp=dummy;
        ListNode t1=h1,t2=h2;

        while(t1!=null && t2!=null){
            if(t1.val<=t2.val){
                temp.next=t1;
                t1=t1.next;
            }else{
                temp.next=t2;
                t2=t2.next;
            }
            temp=temp.next;
        }

        if(t1!=null) temp.next=t1;
        if(t2!=null) temp.next=t2;

        return dummy.next;
    }

    public ListNode divide(ListNode head){
        if(head==null || head.next==null) return head;
        ListNode middle=middleNode(head);
        ListNode nHead=middle.next;
        middle.next=null;
        return merge(divide(head),divide(nHead));
    }

    public ListNode SortList(ListNode head) {
        return divide(head);
    }
}