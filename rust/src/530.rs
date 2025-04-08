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

use std::cell::RefCell;
use std::rc::Rc;

impl Solution {
    pub fn get_minimum_difference(root: Option<Rc<RefCell<TreeNode>>>) -> i32 {
        fn in_order(
            node: Option<Rc<RefCell<TreeNode>>>,
            prev: &mut Option<i32>,
            min_diff: &mut i32,
        ) {
            if let Some(current) = node {
                let current_ref = current.borrow();

                in_order(current_ref.left.clone(), prev, min_diff);

                if let Some(prev_val) = prev {
                    *min_diff = (*min_diff).min((current_ref.val - *prev_val).abs());
                }
                *prev = Some(current_ref.val);

                in_order(current_ref.right.clone(), prev, min_diff);
            }
        }

        let mut prev = None;
        let mut min_diff = i32::MAX;
        in_order(root, &mut prev, &mut min_diff);
        min_diff
    }
}
//sub: https://leetcode.com/problems/minimum-absolute-difference-in-bst/submissions/1600159831/?envType=study-plan-v2&envId=top-interview-150
//sol: https://leetcode.com/problems/minimum-absolute-difference-in-bst/solutions/6627381/530-minimum-absolute-difference-in-bst-b-lk6i/
