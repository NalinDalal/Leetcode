//11. Container With Most Water
function maxArea(height: number[]): number {
  let i = 0,
    j = height.length - 1;
  let ans = 0,
    res = 0;
  while (i < j) {
    ans = (j - i) * Math.min(height[i], height[j]);
    res = Math.max(res, ans);
    if (height[i] < height[j]) i++;
    else j--;
  }
  return res;
}
//sub: https://leetcode.com/problems/container-with-most-water/submissions/1790924712/?envType=daily-question&envId=2025-10-04
//sol: https://leetcode.com/problems/container-with-most-water/solutions/7247604/11-container-with-most-water-by-nalindal-s9o2/
