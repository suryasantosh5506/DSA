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
    public ListNode RotateRight(ListNode head, int k) {
        if(head==null || k==0) return head;
        ListNode tail=head;
        int len=1;
        for(;tail.next!=null;tail=tail.next) len++;
        k=k%len;
        if(k==0) return head;
        int req=len-k-1;
        ListNode temp=head;
        while(req>0){
            temp=temp.next;
            req--;
        }
        ListNode nHead=temp.next;
        temp.next=null;
        tail.next=head;
        head=nHead;
        return head;
    }
}