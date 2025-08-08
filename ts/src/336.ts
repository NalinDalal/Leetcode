//808. Soup Servings
function soupServings(n: number): number {
    if (n >= 4800) return 1.0;

    const N = Math.ceil(n / 25);
    const memo: number[][] = Array.from({ length: N + 1 }, () => Array(N + 1).fill(-1));

    function dfs(a: number, b: number): number {
        if (a <= 0 && b <= 0) return 0.5;
        if (a <= 0) return 1.0;
        if (b <= 0) return 0.0;
        if (memo[a][b] >= 0) return memo[a][b];

        memo[a][b] = 0.25 * (
            dfs(Math.max(a - 4, 0), b) +
            dfs(Math.max(a - 3, 0), Math.max(b - 1, 0)) +
            dfs(Math.max(a - 2, 0), Math.max(b - 2, 0)) +
            dfs(Math.max(a - 1, 0), Math.max(b - 3, 0))
        );

        return memo[a][b];
    }

    return dfs(N, N);
}
//sub: https://leetcode.com/problems/soup-servings/submissions/1727554432/?envType=daily-question&envId=2025-08-08
//sol: https://leetcode.com/problems/soup-servings/solutions/7056532/808-soup-servings-by-nalindalal2004-ylkh/
