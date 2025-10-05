public class MiddleOfLinkedList {

    public Node findMiddle(Node head) {
        // If the list is empty or has one node, the head is the middle.
        if (head == null || head.next == null) {
            return head;
        }

        // Initialize slow and fast pointers at the head.
        Node slow = head;
        Node fast = head;

        // Traverse the list. The fast pointer moves two steps at a time
        // while the slow pointer moves one step.
        while (fast != null && fast.next != null) {
            slow = slow.next;
            fast = fast.next.next;
        }

        // When the fast pointer reaches the end of the list, the slow
        // pointer will be at the middle.
        return slow;
    }
}