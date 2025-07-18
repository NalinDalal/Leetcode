//2163. Minimum Difference in Sums After Removal of Elements
function minimumDifference(nums: number[]): number {
  const n3 = nums.length,
    n = Math.floor(n3 / 3);
  const part1: number[] = new Array(n + 1).fill(0);
  let sum = 0;
  // max heap (simulate with opposite numbers)
  const ql = new MaxPriorityQueue<number>();
  for (let i = 0; i < n; ++i) {
    sum += nums[i];
    ql.enqueue(nums[i]);
  }
  part1[0] = sum;
  for (let i = n; i < n * 2; ++i) {
    sum += nums[i];
    ql.enqueue(nums[i]);
    sum -= ql.dequeue();
    part1[i - (n - 1)] = sum;
  }

  let part2 = 0;
  // min heap
  const qr = new MinPriorityQueue<number>();
  for (let i = n * 3 - 1; i >= n * 2; --i) {
    part2 += nums[i];
    qr.enqueue(nums[i]);
  }
  let ans = part1[n] - part2;
  for (let i = n * 2 - 1; i >= n; --i) {
    part2 += nums[i];
    qr.enqueue(nums[i]);
    part2 -= qr.dequeue();
    ans = Math.min(ans, part1[i - n] - part2);
  }
  return ans;
}
//sub: https://leetcode.com/problems/minimum-difference-in-sums-after-removal-of-elements/submissions/1702057840/?envType=daily-question&envId=2025-07-18
//sol: https://leetcode.com/problems/minimum-difference-in-sums-after-removal-of-elements/solutions/6972926/2163-minimum-difference-in-sums-after-re-l96p/
