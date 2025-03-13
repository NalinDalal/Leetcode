function minZeroArray(nums: number[], queries: number[][]): number {
  let n = nums.length,
    left = 0,
    right = queries.length;

  // Check if it's even possible to make nums all zero
  if (!canFormZeroArray(nums, queries, right)) return -1;

  // Binary search for the minimum number of queries
  while (left <= right) {
    let middle = Math.floor((left + right) / 2);
    if (canFormZeroArray(nums, queries, middle)) {
      right = middle - 1;
    } else {
      left = middle + 1;
    }
  }

  return left;
}

// Function to check if we can make the array zero using the first k queries
function canFormZeroArray(
  nums: number[],
  queries: number[][],
  k: number,
): boolean {
  let n = nums.length,
    sum = 0;
  const differenceArray: number[] = new Array(n + 1).fill(0); // Difference array

  // Apply first k queries
  for (let i = 0; i < k; i++) {
    let start = queries[i][0],
      end = queries[i][1],
      val = queries[i][2];
    differenceArray[start] += val;
    if (end + 1 < n) differenceArray[end + 1] -= val;
  }

  // Apply the difference array to check if nums can be zeroed
  for (let i = 0; i < n; i++) {
    sum += differenceArray[i];
    if (sum < nums[i]) return false; // If nums[i] cannot be zeroed
  }

  return true;
}

// Example Usage
console.log(
  minZeroArray(
    [5, 3, 2],
    [
      [0, 2, 1],
      [1, 2, 2],
      [0, 1, 3],
    ],
  ),
); // Output: Minimum k queries needed
//sub: https://leetcode.com/problems/zero-array-transformation-ii/submissions/1572217963/?envType=daily-question&envId=2025-03-13
//sol: https://leetcode.com/problems/zero-array-transformation-ii/solutions/6531667/3356-zero-array-transformation-ii-by-nal-0njm/
