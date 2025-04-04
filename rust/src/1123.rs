//1123. Lowest Common Ancestor of Deepest Leaves

use std::cell::RefCell;
use std::rc::Rc;

type Node = Option<Rc<RefCell<TreeNode>>>;

#[derive(Debug, PartialEq, Eq)]
pub struct TreeNode {
    pub val: i32,
    pub left: Node,
    pub right: Node,
}

impl TreeNode {
    pub fn new(val: i32) -> Node {
        Some(Rc::new(RefCell::new(TreeNode {
            val,
            left: None,
            right: None,
        })))
    }
}

fn dfs(node: &Node) -> (i32, Node) {
    if node.is_none() {
        return (0, None);
    }

    let node_ref = node.as_ref().unwrap().borrow();
    let (left_depth, left_lca) = dfs(&node_ref.left);
    let (right_depth, right_lca) = dfs(&node_ref.right);

    if left_depth > right_depth {
        (left_depth + 1, left_lca)
    } else if right_depth > left_depth {
        (right_depth + 1, right_lca)
    } else {
        (left_depth + 1, node.clone())
    }
}

pub fn lca_deepest_leaves(root: Node) -> Node {
    dfs(&root).1
}
//sub: https://leetcode.com/problems/lowest-common-ancestor-of-deepest-leaves/submissions/1596502569/?envType=daily-question&envId=2025-04-04
//sol: https://leetcode.com/problems/lowest-common-ancestor-of-deepest-leaves/solutions/6614660/1123-lowest-common-ancestor-of-deepest-l-v4i3/
