//165. Compare Version Numbers
function compareVersion(version1: string, version2: string): number {
  const v1 = version1.split(".").map(Number);
  const v2 = version2.split(".").map(Number);

  const n = Math.max(v1.length, v2.length);

  for (let i = 0; i < n; i++) {
    const num1 = v1[i] ?? 0; // default to 0 if index out of range
    const num2 = v2[i] ?? 0;

    if (num1 < num2) return -1;
    if (num1 > num2) return 1;
  }

  return 0;
}
//sub: https://leetcode.com/problems/compare-version-numbers/submissions/1779796342/?envType=daily-question&envId=2025-09-23
//sol: https://leetcode.com/problems/compare-version-numbers/solutions/7215888/165-compare-version-numbers-by-nalindala-0200/
