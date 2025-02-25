//235. Lowest Common Ancestor of a Binary Search Tree

class TreeNode {
   val: number   left: TreeNode | null
  right: TreeNode | null
    constructor(val?: number, left?: TreeNode | null, right?: TreeNode | null) {
        this.val = (val===undefined ? 0 : val)
        this.left = (left===undefined ? null : left)
        this.right = (right===undefined ? null : right)
    }
}


function lowestCommonAncestor(root: TreeNode | null, p: TreeNode | null, q: TreeNode | null): TreeNode | null {
	if(!root) return null;
    if(root===p || root===q)return root;
    let left=lowestCommonAncestor(root.left,p,q);
    let right = lowestCommonAncestor(root.right, p, q);
        
        if (left && right) return root;
        
        return left ? left : right;
};

//sub: https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-search-tree/submissions/1554432450/
//sol: https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-search-tree/solutions/6464492/235-lowest-common-ancestor-of-a-binary-s-il6c/
