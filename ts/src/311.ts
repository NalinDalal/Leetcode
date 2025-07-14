//1290. Convert Binary Number in a Linked List to Integer
// Definition for singly-linked list.
class ListNode {
  val: number;
  next: ListNode | null;
  constructor(val?: number, next?: ListNode | null) {
    this.val = val === undefined ? 0 : val;
    this.next = next === undefined ? null : next;
  }
}

function getDecimalValue(head: ListNode | null): number {
  let num = 0;
  while (head) {
    num = (num << 1) | head.val;
    head = head.next;
  }
  return num;
}
//sub: https://leetcode.com/problems/convert-binary-number-in-a-linked-list-to-integer/submissions/1697797166/?envType=daily-question&envId=2025-07-14
//sol: https://leetcode.com/problems/convert-binary-number-in-a-linked-list-to-integer/solutions/6958625/1290-convert-binary-number-in-a-linked-l-3syp/
