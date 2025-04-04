//1123. Lowest Common Ancestor of Deepest Leaves
class TreeNode {
  val: number;
  left: TreeNode | null;
  right: TreeNode | null;
  constructor(
    val = 0,
    left: TreeNode | null = null,
    right: TreeNode | null = null,
  ) {
    this.val = val;
    this.left = left;
    this.right = right;
  }
}

function lcaDeepestLeaves(root: TreeNode | null): TreeNode | null {
  function dfs(node: TreeNode | null): [number, TreeNode | null] {
    if (!node) return [0, null];

    const [leftDepth, leftLCA] = dfs(node.left);
    const [rightDepth, rightLCA] = dfs(node.right);

    if (leftDepth > rightDepth) return [leftDepth + 1, leftLCA];
    if (rightDepth > leftDepth) return [rightDepth + 1, rightLCA];
    return [leftDepth + 1, node];
  }

  return dfs(root)[1];
}

//sub: https://leetcode.com/problems/lowest-common-ancestor-of-deepest-leaves/submissions/1596500774/?envType=daily-question&envId=2025-04-04
//sol: https://leetcode.com/problems/lowest-common-ancestor-of-deepest-leaves/solutions/6614660/1123-lowest-common-ancestor-of-deepest-l-v4i3/
