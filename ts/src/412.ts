//3354. Make Array Elements Equal to Zero
function countValidSelections(nums: number[]): number {
  const n = nums.length;
  let valid = 0;

  function simulate(start: number, dir: number): boolean {
    const arr = [...nums]; // make a copy
    let curr = start;

    while (curr >= 0 && curr < n) {
      if (arr[curr] === 0) {
        curr += dir;
      } else {
        arr[curr] -= 1;
        dir *= -1; // reverse direction
        curr += dir;
      }
    }

    return arr.every((x) => x === 0);
  }

  for (let i = 0; i < n; i++) {
    if (nums[i] === 0) {
      if (simulate(i, 1)) valid++; // right
      if (simulate(i, -1)) valid++; // left
    }
  }

  return valid;
}
//sub: https://leetcode.com/problems/make-array-elements-equal-to-zero/submissions/1814298075/?envType=daily-question&envId=2025-10-28
//sol: https://leetcode.com/problems/make-array-elements-equal-to-zero/solutions/7308534/3354-make-array-elements-equal-to-zero-b-8sds/
