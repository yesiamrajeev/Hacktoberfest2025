public class LinkedListCycle {
    
    public boolean hasCycle(Node head) {
        // If the list is empty or has only one node, no cycle can exist.
        if (head == null || head.next == null) {
            return false;
        }

        // Initialize two pointers: slow (tortoise) and fast (hare).
        Node slow = head;
        Node fast = head;

        // Traverse the list with two pointers.
        // The loop continues as long as the fast pointer and the node after it are not null.
        // This prevents a NullPointerException when accessing fast.next.next.
        while (fast != null && fast.next != null) {
            // Move slow pointer by one step.
            slow = slow.next;
            // Move fast pointer by two steps.
            fast = fast.next.next;

            // If the slow and fast pointers meet at any point, a cycle is detected.
            if (slow == fast) {
                return true;
            }
        }

        // If the loop finishes, it means the fast pointer reached the end of the list.
        // Therefore, no cycle exists.
        return false;
    }
}