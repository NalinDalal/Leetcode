// 637. Average of Levels in Binary Tree

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

function averageOfLevels(root: TreeNode | null): number[] {
  const res: number[] = [];
  if (root === null) {
    return res;
  }

  const q: TreeNode[] = [];
  q.push(root);

  while (q.length > 0) {
    const size = q.length;
    let sum = 0;

    for (let i = 0; i < size; i++) {
      const cur = q.shift()!;
      sum += cur.val;

      if (cur.left !== null) {
        q.push(cur.left);
      }
      if (cur.right !== null) {
        q.push(cur.right);
      }
    }

    res.push(sum / size);
  }

  return res;
}
