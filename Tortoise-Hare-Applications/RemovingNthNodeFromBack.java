public class RemoveNthNodeFromEnd {

    public Node removeNthFromEnd(Node head, int n) {
        // Create a dummy node that points to the head. This simplifies edge cases,
        // such as removing the first node of the list.
        Node dummy = new Node(0);
        dummy.next = head;

        // Initialize two pointers, both starting at the dummy node.
        Node slow = dummy;
        Node fast = dummy;

        // 1. Create a gap between slow and fast pointers.
        // Move the fast pointer n + 1 steps ahead. The +1 is because we started from dummy.
        // This places the fast pointer 'n' nodes ahead of the slow pointer in the actual list.
        for (int i = 0; i <= n; i++) {
            fast = fast.next;
        }

        // 2. Move both pointers together until the fast pointer reaches the end (null).
        // By the end of this loop, the slow pointer will be positioned just before
        // the node that needs to be removed.
        while (fast != null) {
            slow = slow.next;
            fast = fast.next;
        }

        // 3. Remove the target node by updating the 'next' pointer.
        // slow.next is the node to be removed. We bypass it by pointing
        // slow.next to the node after the target node (slow.next.next).
        slow.next = slow.next.next;

        // Return the head of the modified list, which is dummy.next.
        return dummy.next;
    }
}