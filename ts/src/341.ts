//326. Power of Three
function isPowerOfThree(n: number): boolean {
  if (n <= 0) return false;

        const x = Math.log(n) / Math.log(3);
        const diff = Math.abs(x - Math.round(x));

        return diff < 1e-10;
};
//sub: https://leetcode.com/problems/power-of-three/submissions/1733186222/?envType=daily-question&envId=2025-08-13
//sol: https://leetcode.com/problems/power-of-three/solutions/7073579/326-power-of-three-by-nalindalal2004-4mj7/
