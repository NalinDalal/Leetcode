//2011. Final Value of Variable After Performing Operations
function finalValueAfterOperations(operations: string[]): number {
  let X: number = 0;
  for (const op of operations) {
    if (op.includes("+")) X++;
    else X--;
  }
  return X;
}
//sub: https://leetcode.com/problems/final-value-of-variable-after-performing-operations/submissions/1806654471/?envType=daily-question&envId=2025-10-20
//sol: https://leetcode.com/problems/final-value-of-variable-after-performing-operations/solutions/7288260/2011-final-value-of-variable-after-perfo-fbwl/
