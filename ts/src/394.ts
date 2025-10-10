//3147. Taking Maximum Energy From the Mystic Dungeon
function maximumEnergy(energy: number[], k: number): number {
    let n=energy.length;
    let dp = new Array(n).fill(0);

    let ans= -Infinity;
    for (let i = n - 1; i >= 0; --i) {
            dp[i] = energy[i];
            if (i + k < n) dp[i] += dp[i + k];
            ans = Math.max(ans, dp[i]);
        }
    return ans;
};
//sub: https://leetcode.com/problems/taking-maximum-energy-from-the-mystic-dungeon/submissions/1797125537/?envType=daily-question&envId=2025-10-10
//sol: https://leetcode.com/problems/taking-maximum-energy-from-the-mystic-dungeon/solutions/7263748/3147-taking-maximum-energy-from-the-myst-2hzh/
