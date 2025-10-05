// Detecting cycle in LinkedList

class ListNode {
    int val;
    ListNode next;

    ListNode(int val) {
        this.val = val;
        this.next = null;
    }
}

public class TortoiseAndHare {
    // Function to detect cycle
    public static boolean hasCycle(ListNode head) {
        if (head == null || head.next == null) {
            return false; 
        }

        ListNode slow = head;
        ListNode fast = head;

        while (fast != null && fast.next != null) {
            slow = slow.next;        
            fast = fast.next.next; 

            if (slow == fast) {
                return true; 
            }
        }

        return false; 
    }


    public static void main(String[] args) {

        ListNode head = new ListNode(1);
        head.next = new ListNode(2);
        head.next.next = new ListNode(3);
        head.next.next.next = new ListNode(4);
        head.next.next.next.next = new ListNode(5);

        head.next.next.next.next.next = head.next;

        boolean result = hasCycle(head);
        if (result) {
            System.out.println("Cycle exist in the linked list.");
        } else {
            System.out.println("No cycle exist in the linked list.");
        }
    }
}
