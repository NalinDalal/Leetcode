//1550. Three Consecutive Odds

function threeConsecutiveOdds(arr: number[]): boolean {
  let ans: boolean = false;
  if (arr.length <= 2) return ans;
  for (let i = 0; i < arr.length - 2; i++) {
    // three consecutive odd numbers
    if (arr[i] % 2 && arr[i + 1] % 2 && arr[i + 2] % 2) ans = true;
  }
  return ans;
}
//sub: https://leetcode.com/problems/three-consecutive-odds/submissions/1630816390/?envType=daily-question&envId=2025-05-11
