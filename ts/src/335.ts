//3363. Find the Maximum Number of Fruits Collected
function maxCollectedFruits(fruits: number[][]): number {
    const n = fruits.length;
    let ans = 0;

    // Diagonal (child at (0, 0))
    for (let i = 0; i < n; i++) {
        ans += fruits[i][i];
    }

    const dp = (): number => {
        let prev = new Array(n).fill(Number.MIN_SAFE_INTEGER);
        let curr = new Array(n).fill(Number.MIN_SAFE_INTEGER);

        prev[n - 1] = fruits[0][n - 1];

        for (let i = 1; i < n - 1; i++) {
            const start = Math.max(n - 1 - i, i + 1);
            for (let j = start; j < n; j++) {
                let best = prev[j];
                if (j - 1 >= 0) best = Math.max(best, prev[j - 1]);
                if (j + 1 < n) best = Math.max(best, prev[j + 1]);
                curr[j] = best + fruits[i][j];
            }
            [prev, curr] = [curr, prev];
        }

        return prev[n - 1];
    };

    ans += dp();

    // Flip along main diagonal (transpose)
    for (let i = 0; i < n; i++) {
        for (let j = 0; j < i; j++) {
            const tmp = fruits[i][j];
            fruits[i][j] = fruits[j][i];
            fruits[j][i] = tmp;
        }
    }

    ans += dp();

    return ans;
}
//sub: https://leetcode.com/problems/find-the-maximum-number-of-fruits-collected/submissions/1726431788/?envType=daily-question&envId=2025-08-07
//sol: https://leetcode.com/problems/find-the-maximum-number-of-fruits-collected/solutions/7053308/3363-find-the-maximum-number-of-fruits-c-t5zg/
