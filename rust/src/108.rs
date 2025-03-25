//108. Convert Sorted Array to Binary Search Tree
// Definition for a binary tree node.
use std::cell::RefCell;
use std::rc::Rc;
#[derive(Debug, PartialEq, Eq)]
pub struct TreeNode {
    pub val: i32,
    pub left: Option<Rc<RefCell<TreeNode>>>,
    pub right: Option<Rc<RefCell<TreeNode>>>,
}

impl TreeNode {
    #[inline]
    pub fn new(val: i32) -> Self {
        TreeNode {
            val,
            left: None,
            right: None,
        }
    }
}

impl Solution {
    pub fn sorted_array_to_bst(nums: Vec<i32>) -> Option<Rc<RefCell<TreeNode>>> {
        Self::build_tree(&nums, 0, nums.len() as i32 - 1)
    }
    fn build_tree(nums: &Vec<i32>, start: i32, end: i32) -> Option<Rc<RefCell<TreeNode>>> {
        if start > end {
            return None;
        }

        let mid = (start + end) / 2;
        let node = Rc::new(RefCell::new(TreeNode::new(nums[mid as usize])));

        node.borrow_mut().left = Self::build_tree(nums, start, mid - 1);
        node.borrow_mut().right = Self::build_tree(nums, mid + 1, end);

        Some(node)
    }
}
