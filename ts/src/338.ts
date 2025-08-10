//869. Reordered Power of 2
function reorderedPowerOf2(n: number): boolean {
    const sig = (x: number): string => {
        return x.toString().split("").sort().join("");
    };

    const target = sig(n);
    for (let i = 0; i < 31; i++) { // 2^0 to 2^30 fits in 32-bit int
        if (sig(1 << i) === target) {
            return true;
        }
    }
    return false;
};
//sub: https://leetcode.com/problems/reordered-power-of-2/submissions/1729607407/?envType=daily-question&envId=2025-08-10
//sol: https://leetcode.com/problems/reordered-power-of-2/solutions/7062756/869-reordered-power-of-2-by-nalindalal20-j6kz/
