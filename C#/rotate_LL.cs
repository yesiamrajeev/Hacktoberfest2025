public ListNode RotateRight(ListNode head, int k)
{
    if (head == null || head.next == null || k == 0) return head;

    int length = 1;
    ListNode tail = head;
    while (tail.next != null)
    {
        tail = tail.next;
        length++;
    }

    k %= length;
    if (k == 0) return head;

    tail.next = head;
    for (int i = 0; i < length - k; i++)
        tail = tail.next;

    ListNode newHead = tail.next;
    tail.next = null;
    return newHead;
}
