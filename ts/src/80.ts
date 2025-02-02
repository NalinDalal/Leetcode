//1752. Check if Array Is Sorted and Rotated

function check(nums: number[]): boolean {
  let countBreaks = 0;
  const n = nums.length;

  for (let i = 0; i < n; i++) {
    if (nums[i] > nums[(i + 1) % n]) {
      countBreaks++;
    }
  }

  return countBreaks <= 1;
}

//sol:
//https://leetcode.com/problems/check-if-array-is-sorted-and-rotated/solutions/6364065/1752-check-if-array-is-sorted-and-rotate-dn3t/
