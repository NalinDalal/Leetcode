//231. Power of Two
function isPowerOfTwo(n: number): boolean {
    return n > 0 && (n & (n - 1)) === 0;
}
//sub: https://leetcode.com/problems/power-of-two/submissions/1728582122/?envType=daily-question&envId=2025-08-09
//sol: https://leetcode.com/problems/power-of-two/solutions/7059789/231-power-of-two-by-nalindalal2004-fv57/
