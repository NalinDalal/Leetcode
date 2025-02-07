// 148. Sort List
//Definition for singly-linked list.
class ListNode {
    val: number
    next: ListNode | null
    constructor(val?: number, next?: ListNode | null) {
        this.val = (val===undefined ? 0 : val)
        this.next = (next===undefined ? null : next)
    }
}


function sortList(head: ListNode | null): ListNode | null {
    if (!head || !head.next) return head;

        // Step 1: Split the list into two halves
        let mid = getMiddle(head);
        let right = mid.next;
        mid.next = null; // Break the list into two halves

        // Step 2: Recursively sort both halves
        let leftSorted = sortList(head);
        let rightSorted = sortList(right);

        // Step 3: Merge the sorted halves
        return merge(leftSorted, rightSorted);
    }

    private function getMiddle(head: ListNode): ListNode {
        let slow: ListNode = head;
        let fast: ListNode | null = head.next; // Start fast one step ahead for better split

        while (fast && fast.next) {
            slow = slow.next!;
            fast = fast.next.next;
        }
        return slow;
    }

    private function merge(l1: ListNode | null, l2: ListNode | null): ListNode | null {
        let dummy = new ListNode(0);
        let tail = dummy;

        while (l1 && l2) {
            if (l1.val < l2.val) {
                tail.next = l1;
                l1 = l1.next;
            } else {
                tail.next = l2;
                l2 = l2.next;
            }
            tail = tail.next;
        }

        // Attach remaining nodes
        tail.next = l1 ?? l2;
        return dummy.next;
    
};

//sub: https://leetcode.com/problems/sort-list/submissions/1534396781/
//sol: https://leetcode.com/problems/sort-list/solutions/6387909/148-sort-list-by-nalindalal2004-v27u/
