//837. New 21 Game
function new21Game(n: number, k: number, maxPts: number): number {
    const dp: number[] = new Array(n + 1).fill(0);
    dp[0] = 1;
    let s = k > 0 ? 1 : 0;

    for (let i = 1; i <= n; i++) {
        dp[i] = s / maxPts;
        if (i < k) {
            s += dp[i];
        }
        if (i - maxPts >= 0 && i - maxPts < k) {
            s -= dp[i - maxPts];
        }
    }

    return dp.slice(k).reduce((acc, val) => acc + val, 0);
};
//sub: https://leetcode.com/problems/new-21-game/submissions/1737997239/?envType=daily-question&envId=2025-08-17
//sol: https://leetcode.com/problems/new-21-game/solutions/7090702/837-new-21-game-by-nalindalal2004-wt5i/
