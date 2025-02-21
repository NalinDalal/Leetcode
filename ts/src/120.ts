//1261. Find Elements in a Contaminated Binary Tree
// Definition for a binary tree node.
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

class FindElements {
  private values: Set<number> = new Set();

  constructor(root: TreeNode | null) {
    if (root) {
      this.recover(root, 0);
    }
  }

  private recover(node: TreeNode | null, value: number): void {
    if (!node) return;

    node.val = value;
    this.values.add(value);

    this.recover(node.left, 2 * value + 1);
    this.recover(node.right, 2 * value + 2);
  }

  find(target: number): boolean {
    return this.values.has(target); // O(1) lookup
  }
}

/**
 * Your FindElements object will be instantiated and called as such:
 */
var obj = new FindElements(root);
var param_1 = obj.find(target);
//sub: https://leetcode.com/problems/find-elements-in-a-contaminated-binary-tree/submissions/1550452174/?envType=daily-question&envId=2025-02-21
//sol: https://leetcode.com/problems/find-elements-in-a-contaminated-binary-tree/solutions/6449855/1261-find-elements-in-a-contaminated-bin-xy1f/
