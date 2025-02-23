//889. Construct Binary Tree from Preorder and Postorder Traversal
/**
 * Definition for a binary tree node.
 * class TreeNode {
 *     val: number
 *     left: TreeNode | null
 *     right: TreeNode | null
 *     constructor(val?: number, left?: TreeNode | null, right?: TreeNode | null) {
 *         this.val = (val===undefined ? 0 : val)
 *         this.left = (left===undefined ? null : left)
 *         this.right = (right===undefined ? null : right)
 *     }
 * }
 */

let preIndex: number = 0;

function constructTree(
  pre: number[],
  post: number[],
  postStart: number,
  postEnd: number,
): TreeNode | null {
  // Base Case: If preIndex is out of range or postStart > postEnd
  if (preIndex >= pre.length || postStart > postEnd) {
    return null;
  }

  // Create a new node with the current preorder value
  let root = new TreeNode(pre[preIndex++]);

  // If there's only one element in this subtree, return it
  if (postStart === postEnd) {
    return root;
  }

  // Find the left subtree root in postorder
  let leftSubtreeRootVal = pre[preIndex];
  let postIndex = postStart;
  while (postIndex <= postEnd && post[postIndex] !== leftSubtreeRootVal) {
    postIndex++;
  }

  // Recursively construct left and right subtrees
  root.left = constructTree(pre, post, postStart, postIndex);
  root.right = constructTree(pre, post, postIndex + 1, postEnd - 1);

  return root;
}

function constructFromPrePost(pre: number[], post: number[]): TreeNode | null {
  preIndex = 0; // Reset the preorder index
  return constructTree(pre, post, 0, post.length - 1);
}

//sub: https://leetcode.com/problems/construct-binary-tree-from-preorder-and-postorder-traversal/submissions/1552572469/?envType=daily-question&envId=2025-02-23
//sol: https://leetcode.com/problems/construct-binary-tree-from-preorder-and-postorder-traversal/solutions/6458117/889-construct-binary-tree-from-preorder-vuq7g/
