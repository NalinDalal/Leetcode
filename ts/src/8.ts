/*230. Kth Smallest Element in a BST
Given the root of a binary search tree, and an integer k, return the kth
smallest value (1-indexed) of all the values of the nodes in the tree.



Example 1:
Input: root = [3,1,4,null,2], k = 1
Output: 1

*/

//Definition for a binary tree node.
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

let count: number = 0; // Keeps track of the number of nodes visited
let result: number = -1; // Stores the k-th smallest value

function inorder(root:TreeNode|null,k:number):number{
    if(root==null)  return;
//traverse left subtree
    inorder(root:root.left,k:number);
    count++;    //increase count for each node visited
    
    //if count match k, set result
    if(count==k){
        result=root.val;return;
    }
    inorder(root.right,k);
}
function kthSmallest(root: TreeNode | null, k: number): number {
    count = 0;  // Reset count before starting the traversal
    result = -1; // Reset result before starting the traversal
inorder(root,k);
    return result;
}


/* https://leetcode.com/problems/kth-smallest-element-in-a-bst/submissions/1491337793/
 * */
