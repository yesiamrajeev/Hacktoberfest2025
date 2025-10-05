/*
 Hacktoberfest 2025 Contribution
 File: SlowFastPointerExamples.java

 This file contains three linked list algorithms using the
 Slow and Fast Pointer (Tortoise & Hare) technique:

 1. Detecting a cycle in a linked list
 2. Finding the middle node of a linked list
 3. Removing the Nth node from the end of a linked list

 Each section is well-commented and includes a demo main method.
*/

import java.util.*;

public class SlowFastPointerExamples {

    // ======= ListNode Definition =======
    static class ListNode {
        int val;
        ListNode next;
        ListNode(int v) { val = v; next = null; }
    }

    // ======= 1. Detect Cycle in Linked List =======
    static class DetectCycle {
        // Returns true if there is a cycle
        public static boolean hasCycle(ListNode head) {
            if (head == null || head.next == null) return false;
            ListNode slow = head;
            ListNode fast = head;
            while (fast != null && fast.next != null) {
                slow = slow.next;
                fast = fast.next.next;
                if (slow == fast) return true; // cycle detected
            }
            return false; // no cycle
        }

        // Helper to build list with optional cycle
        public static ListNode buildList(int[] arr, int pos) {
            if (arr.length == 0) return null;
            ListNode head = new ListNode(arr[0]);
            ListNode cur = head;
            ListNode cycleNode = (pos == 0) ? head : null;
            for (int i = 1; i < arr.length; i++) {
                cur.next = new ListNode(arr[i]);
                cur = cur.next;
                if (i == pos) cycleNode = cur;
            }
            if (pos >= 0) cur.next = cycleNode; // create cycle
            return head;
        }

        // Demo
        public static void demo() {
            int[] vals = {3, 2, 0, -4};
            int pos = 1; // create cycle
            ListNode head = buildList(vals, pos);
            System.out.println("DetectCycle demo: Has cycle? " + hasCycle(head)); // true

            ListNode head2 = buildList(new int[]{1, 2, 3, 4}, -1);
            System.out.println("DetectCycle demo: Has cycle? " + hasCycle(head2)); // false
        }
    }

    // ======= 2. Find Middle Node =======
    static class MiddleOfLinkedList {
        public static ListNode middleNode(ListNode head) {
            if (head == null) return null;
            ListNode slow = head;
            ListNode fast = head;
            while (fast != null && fast.next != null) {
                slow = slow.next;        // move by 1
                fast = fast.next.next;   // move by 2
            }
            return slow;
        }

        public static ListNode build(int[] arr) {
            if (arr.length == 0) return null;
            ListNode head = new ListNode(arr[0]);
            ListNode cur = head;
            for (int i = 1; i < arr.length; i++) {
                cur.next = new ListNode(arr[i]);
                cur = cur.next;
            }
            return head;
        }

        public static void printList(ListNode head) {
            ListNode cur = head;
            while (cur != null) {
                System.out.print(cur.val);
                if (cur.next != null) System.out.print(" -> ");
                cur = cur.next;
            }
            System.out.println();
        }

        // Demo
        public static void demo() {
            ListNode head = build(new int[]{1,2,3,4,5});
            System.out.print("MiddleOfLinkedList demo: List: "); printList(head);
            ListNode mid = middleNode(head);
            System.out.println("Middle value: " + (mid != null ? mid.val : "null")); // 3

            ListNode even = build(new int[]{1,2,3,4,5,6});
            System.out.print("MiddleOfLinkedList demo (even): "); printList(even);
            ListNode midEven = middleNode(even);
            System.out.println("Middle value (even, 2nd middle): " + (midEven != null ? midEven.val : "null")); // 4
        }
    }

    // ======= 3. Remove N-th Node From End =======
    static class RemoveNthFromEnd {
        public static ListNode removeNthFromEnd(ListNode head, int n) {
            ListNode dummy = new ListNode(0);
            dummy.next = head;
            ListNode first = dummy;
            ListNode second = dummy;
            // Advance first by n+1
            for (int i = 0; i <= n; i++) {
                if (first != null) first = first.next;
            }
            // Move both until first reaches end
            while (first != null) {
                first = first.next;
                second = second.next;
            }
            // Remove target node
            if (second.next != null) second.next = second.next.next;
            return dummy.next;
        }

        // Demo helpers
        public static ListNode build(int[] arr) {
            if (arr.length == 0) return null;
            ListNode head = new ListNode(arr[0]);
            ListNode cur = head;
            for (int i = 1; i < arr.length; i++) {
                cur.next = new ListNode(arr[i]);
                cur = cur.next;
            }
            return head;
        }

        public static void printList(ListNode head) {
            ListNode cur = head;
            while (cur != null) {
                System.out.print(cur.val);
                if (cur.next != null) System.out.print(" -> ");
                cur = cur.next;
            }
            System.out.println();
        }

        // Demo
        public static void demo() {
            ListNode head = build(new int[]{1,2,3,4,5});
            System.out.print("RemoveNthFromEnd demo: Original: "); printList(head);
            head = removeNthFromEnd(head, 2);
            System.out.print("After removing 2nd from end: "); printList(head); // 1->2->3->5

            ListNode head2 = build(new int[]{1,2});
            System.out.print("RemoveNthFromEnd demo: Original: "); printList(head2);
            head2 = removeNthFromEnd(head2, 2);
            System.out.print("After removing 2nd from end (remove head): "); printList(head2); // 2
        }
    }

    // ======= Main Demo =======
    public static void main(String[] args) {
        System.out.println("=== DetectCycle Demo ===");
        DetectCycle.demo();

        System.out.println("\n=== MiddleOfLinkedList Demo ===");
        MiddleOfLinkedList.demo();

        System.out.println("\n=== RemoveNthFromEnd Demo ===");
        RemoveNthFromEnd.demo();
    }
}
