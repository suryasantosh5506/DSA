/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode() {}
 *     ListNode(int val) { this.val = val; }
 *     ListNode(int val, ListNode next) { this.val = val; this.next = next; }
 * }
 */
class Solution {
    public ListNode rotateRight(ListNode head, int k) {
        if(head==null) return head;

        ListNode tail=head;
        int size=1;

        while(tail.next!=null){
            tail=tail.next;
            size++;
        }

        k=k%size;
        if(k==0) return head;

        ListNode temp=head;
        int req=size-k;
        while(req>1){
            temp=temp.next;
            req--;
        }

        tail.next=head;
        head=temp.next;
        temp.next=null;
        return head;
    }
}