//103. Binary Tree Zigzag Level Order Traversal
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

function zigzagLevelOrder(root: TreeNode | null): number[][] {
  const result: number[][] = [];
  if (!root) return result;

  const queue: TreeNode[] = [root];
  let leftToRight = true;

  while (queue.length > 0) {
    const levelSize = queue.length;
    const level: number[] = new Array(levelSize);

    for (let i = 0; i < levelSize; i++) {
      const node = queue.shift()!;
      const index = leftToRight ? i : levelSize - 1 - i;
      level[index] = node.val;

      if (node.left) queue.push(node.left);
      if (node.right) queue.push(node.right);
    }

    result.push(level);
    leftToRight = !leftToRight; // Toggle direction
  }

  return result;
}

//sub:https://leetcode.com/problems/binary-tree-zigzag-level-order-traversal/submissions/1556128765/
//sol:https://leetcode.com/problems/binary-tree-zigzag-level-order-traversal/solutions/6470785/103-binary-tree-zigzag-level-order-trave-sihb/
