//342. Power of Four
function isPowerOfFour(n: number): boolean {
if (n <= 0) return false;

        const x = Math.log(n) / Math.log(4);
        const diff = Math.abs(x - Math.round(x));

        return diff < 1e-10;
}
    //sub: https://leetcode.com/problems/power-of-four/submissions/1735522771/?envType=daily-question&envId=2025-08-15
//sol: https://leetcode.com/problems/power-of-four/solutions/7081991/342-power-of-four-by-nalindalal2004-1gfn/
