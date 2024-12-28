// 96. Unique Binary Search Trees
function numTrees(n: number): number {
  //int uniqTree(n+1,1);
  const uniqTree: number[] = Array(n + 1).fill(1); // Initialize an array with 1's

  for (let nodes = 2; nodes <= n; nodes++) {
    let total: number = 0;
    for (let root: number = 1; root <= nodes; root++) {
      total += uniqTree[root - 1] * uniqTree[nodes - root];
    }
    uniqTree[nodes] = total;
  }
  return uniqTree[n];
}

// https://leetcode.com/problems/unique-binary-search-trees/submissions/1490366783/
