//1290. Convert Binary Number in a Linked List to Integer
// Definition for singly-linked list.
// #[derive(PartialEq, Eq, Clone, Debug)]
// pub struct ListNode {
//   pub val: i32,
//   pub next: Option<Box<ListNode>>
// }
//
// impl ListNode {
//   #[inline]
//   fn new(val: i32) -> Self {
//     ListNode {
//       next: None,
//       val
//     }
//   }
// }
impl Solution {
    pub fn get_decimal_value(mut head: Option<Box<ListNode>>) -> i32 {
        let mut num = 0;
        while let Some(node) = head {
            num = (num << 1) | node.val;
            head = node.next;
        }
        num
    }
}
//sub: https://leetcode.com/problems/convert-binary-number-in-a-linked-list-to-integer/submissions/1697801326/
//sol: https://leetcode.com/problems/convert-binary-number-in-a-linked-list-to-integer/solutions/6958625/1290-convert-binary-number-in-a-linked-l-3syp/
