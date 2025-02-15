// 2698. Find the Punishment Number of an Integer
function punishmentNumber(n: number): number {
  let totalPunishment: number = 0;
  for (let i = 1; i <= n; i++) {
    let squared = i * i;
    let numStr: string = squared.toString();

    // Check if the squared number can be partitioned to sum to i
    if (canPartition(numStr, i)) {
      totalPunishment += squared;
    }
  }
  return totalPunishment;
}

function canPartition(
  numStr: string,
  target: number,
  index: number,
  currentSum: number,
): boolean {
  if (currentSum > target) return false; // Optimization: Stop early if sum exceeds target
  if (index === numStr.length) return currentSum === target;

  let num = 0;
  for (let i = index; i < numStr.length; i++) {
    num = num * 10 + (numStr[i].charCodeAt(0) - "0".charCodeAt(0)); // Convert character to number
    if (canPartition(numStr, target, i + 1, currentSum + num)) {
      return true;
    }
  }
  return false;
}
//sub: https://leetcode.com/problems/find-the-punishment-number-of-an-integer/submissions/1543428668/?envType=daily-question&envId=2025-02-15
//sol: https://leetcode.com/problems/find-the-punishment-number-of-an-integer/solutions/6423689/2698-find-the-punishment-number-of-an-in-mwou/
