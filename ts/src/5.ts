//689. Maximum Sum of 3 Non-Overlapping Subarrays

function maxSumOfThreeSubarrays(nums: number[], k: number): number[] {
  const n = nums.length;

  // Step 1: Precompute the sums of all subarrays of length k
  const subarraySums: number[] = new Array(n - k + 1).fill(0);
  let currentSum = 0;
  for (let i = 0; i < n; i++) {
    currentSum += nums[i];
    if (i >= k - 1) {
      subarraySums[i - k + 1] = currentSum;
      currentSum -= nums[i - k + 1];
    }
  }

  // Step 2: Use DP to find max subarray sums for intervals ending at specific indices
  const left: number[] = new Array(n - k + 1).fill(0);
  const right: number[] = new Array(n - k + 1).fill(n - k);

  // Calculate left: max subarray ending at or before each index
  let maxIdx = 0;
  for (let i = 0; i < subarraySums.length; i++) {
    if (subarraySums[i] > subarraySums[maxIdx]) {
      maxIdx = i;
    }
    left[i] = maxIdx;
  }

  // Calculate right: max subarray starting at or after each index
  maxIdx = n - k;
  for (let i = subarraySums.length - 1; i >= 0; i--) {
    if (subarraySums[i] >= subarraySums[maxIdx]) {
      maxIdx = i;
    }
    right[i] = maxIdx;
  }

  // Step 3: Backtrack to find the indices of three subarrays
  let result = [-1, -1, -1];
  let maxSum = 0;
  for (let mid = k; mid <= n - 2 * k; mid++) {
    const l = left[mid - k];
    const r = right[mid + k];
    const currentSum = subarraySums[l] + subarraySums[mid] + subarraySums[r];
    if (currentSum > maxSum) {
      maxSum = currentSum;
      result = [l, mid, r];
    }
  }

  return result;
}

// Example usage:
const nums = [7, 13, 20, 19, 19, 2, 10, 1, 1, 19];
const k = 3;
console.log(maxSumOfThreeSubarrays(nums, k)); // Output: [0, 3, 7]
