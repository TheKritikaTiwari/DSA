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
    public ListNode reverseList(ListNode head) {
        if(head==null || head.next==null) return head;
        ListNode tail=head, temp=head;
        int start=0, end=0;
        while(tail.next!=null){
            tail=tail.next;
            end++;
        }
        while(start<=end){
            int t = temp.val;
            temp.val  = tail.val;
            tail.val = t;
            ListNode current=head;
            while(current.next!=tail){
                current=current.next;
            }
            tail=current;
            temp=temp.next;
            start++;
            end--;
        }
        return head;

   }
}