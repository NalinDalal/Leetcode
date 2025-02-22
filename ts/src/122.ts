//1028. Recover a Tree From Preorder Traversal
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

function recoverFromPreorder(traversal: string): TreeNode | null {
  let indexRef = { value: 0 }; // Use an object to keep a reference
  return helper(traversal, indexRef, 0);
}

function helper(
  traversal: string,
  indexRef: { value: number },
  depth: number,
): TreeNode | null {
  if (indexRef.value >= traversal.length) return null;

  // Count the number of dashes
  let dashCount = 0;
  while (
    indexRef.value + dashCount < traversal.length &&
    traversal[indexRef.value + dashCount] === "-"
  ) {
    dashCount++;
  }

  // If the number of dashes doesn't match the current depth, return null
  if (dashCount !== depth) return null;

  // Move index past the dashes
  indexRef.value += dashCount;

  // Extract the node value
  let value = 0;
  while (
    indexRef.value < traversal.length &&
    /\d/.test(traversal[indexRef.value])
  ) {
    value =
      value * 10 +
      (traversal[indexRef.value].charCodeAt(0) - "0".charCodeAt(0));
    indexRef.value++;
  }

  // Create the current node
  const node = new TreeNode(value);

  // Recursively build the left and right subtrees
  node.left = helper(traversal, indexRef, depth + 1);
  node.right = helper(traversal, indexRef, depth + 1);

  return node;
}
//sub: https://leetcode.com/problems/recover-a-tree-from-preorder-traversal/submissions/1551628076/?envType=daily-question&envId=2025-02-22
//sol: https://leetcode.com/problems/recover-a-tree-from-preorder-traversal/solutions/6454721/1028-recover-a-tree-from-preorder-traver-bg6w/
