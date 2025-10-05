/**
 * Slow and Fast Pointer (Tortoise & Hare) Algorithms in Java
 * 
 * This class demonstrates three fundamental linked list problems using
 * the Slow and Fast Pointer technique:
 * 1. Detecting a cycle in a linked list
 * 2. Finding the middle node of a linked list
 * 3. Removing the Nth node from the end of a linked list
 * 
 * All algorithms run in O(n) time with O(1) extra space.
 */

class ListNode {
    int val;
    ListNode next;
    ListNode(int val) { this.val = val; }
}

public class SlowFastPointerExamples {

    // ----------------- 1️⃣ Detect Cycle in Linked List -----------------
    public static boolean hasCycle(ListNode head) {
        if (head == null || head.next == null) return false;

        ListNode slow = head; // moves 1 step at a time
        ListNode fast = head; // moves 2 steps at a time

        while (fast != null && fast.next != null) {
            slow = slow.next;
            fast = fast.next.next;

            if (slow == fast) return true; // cycle detected
        }
        return false; // no cycle
    }

    // ----------------- 2️⃣ Find Middle Node of Linked List -----------------
    public static ListNode findMiddle(ListNode head) {
        if (head == null) return null;

        ListNode slow = head;
        ListNode fast = head;

        while (fast != null && fast.next != null) {
            slow = slow.next;      // move slow by 1
            fast = fast.next.next; // move fast by 2
        }

        return slow; // slow is now at the middle
    }

    // ----------------- 3️⃣ Remove Nth Node from End -----------------
    public static ListNode removeNthFromEnd(ListNode head, int n) {
        ListNode dummy = new ListNode(0);
        dummy.next = head;
        ListNode first = dummy;
        ListNode second = dummy;

        // Move first pointer n+1 steps ahead
        for (int i = 0; i <= n; i++) {
            first = first.next;
        }

        // Move both pointers until first reaches the end
        while (first != null) {
            first = first.next;
            second = second.next;
        }

        // Remove the nth node
        second.next = second.next.next;

        return dummy.next;
    }

    // ----------------- Main Method to Test All Examples -----------------
    public static void main(String[] args) {

        // --- Example 1: Detect Cycle ---
        ListNode head1 = new ListNode(1);
        head1.next = new ListNode(2);
        head1.next.next = new ListNode(3);
        head1.next.next.next = head1; // creates a cycle
        System.out.println("Cycle present? " + hasCycle(head1));

        // --- Example 2: Find Middle Node ---
        ListNode head2 = new ListNode(1);
        head2.next = new ListNode(2);
        head2.next.next = new ListNode(3);
        head2.next.next.next = new ListNode(4);
        head2.next.next.next.next = new ListNode(5);
        ListNode middle = findMiddle(head2);
        System.out.println("Middle node value: " + middle.val);

        // --- Example 3: Remove Nth Node from End ---
        ListNode head3 = new ListNode(1);
        head3.next = new ListNode(2);
        head3.next.next = new ListNode(3);
        head3.next.next.next = new ListNode(4);
        head3.next.next.next.next = new ListNode(5);

        head3 = removeNthFromEnd(head3, 2); // remove 2nd node from end
        System.out.print("Linked list after removal: ");
        ListNode temp = head3;
        while (temp != null) {
            System.out.print(temp.val + " -> ");
            temp = temp.next;
        }
        System.out.println("null");
    }
}
