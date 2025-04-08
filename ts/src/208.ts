//530. Minimum Absolute Difference in BST

class TreeNode {
  val: number;
  left: TreeNode | null;
  right: TreeNode | null;
  constructor(val?: number, left?: TreeNode | null, right?: TreeNode | null) {
    this.val = val === undefined ? 0 : val;
    this.left = left === undefined ? null : left;
    this.right = right === undefined ? null : right;
  }
}

function getMinimumDifference(root: TreeNode | null): number {
  let prev: number | null = null;
  let minDiff = Infinity;

  function inOrder(node: TreeNode | null) {
    if (!node) return;

    inOrder(node.left);

    if (prev !== null) {
      minDiff = Math.min(minDiff, Math.abs(node.val - prev));
    }
    prev = node.val;

    inOrder(node.right);
  }

  inOrder(root);
  return minDiff;
}

//sub: https://leetcode.com/problems/minimum-absolute-difference-in-bst/submissions/1600158251/?envType=study-plan-v2&envId=top-interview-150
//sol: https://leetcode.com/problems/minimum-absolute-difference-in-bst/solutions/6627381/530-minimum-absolute-difference-in-bst-b-lk6i/
