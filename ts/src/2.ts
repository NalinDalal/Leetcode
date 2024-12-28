//222. Count Complete Tree nodes
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

//The return 0:number and return left+right+1:number are incorrect. The correct way to specify the return type in TypeScript is by using the function signature rather than inside the return statement.
/*
function countNodes(root: TreeNode | null): number {
    // every level except lasy is completwly filled
    if(root==null)  return 0:number;
    let left:number=countNodes(root.left);
    let right:number=countNodes(root.right);
    return left+right+1:number;
};*/

function countNodes(root: TreeNode | null): number {
  // every level except last is completwly filled

  if (root == null) return 0;

  let left = countNodes(root.left);
  let right = countNodes(root.right);

  return left + right + 1;
}
