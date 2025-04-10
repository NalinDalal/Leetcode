//2999. Count the Number of Powerful Integers
function numberOfPowerfulInt(
  start: number,
  finish: number,
  limit: number,
  s: string,
): number {
  const low = start.toString().padStart(finish.toString().length, "0");
  const high = finish.toString();
  const n = high.length;
  const preLen = n - s.length;

  const memo: (number | null)[] = Array(n).fill(null);

  const dfs = (i: number, limitLow: boolean, limitHigh: boolean): number => {
    if (i === n) return 1;

    if (!limitLow && !limitHigh && memo[i] !== null) return memo[i]!;

    const lo = limitLow ? Number(low[i]) : 0;
    const hi = limitHigh ? Number(high[i]) : 9;

    let res = 0;
    if (i < preLen) {
      for (let digit = lo; digit <= Math.min(hi, limit); digit++) {
        res += dfs(i + 1, limitLow && digit === lo, limitHigh && digit === hi);
      }
    } else {
      const x = Number(s[i - preLen]);
      if (x >= lo && x <= Math.min(hi, limit)) {
        res += dfs(i + 1, limitLow && x === lo, limitHigh && x === hi);
      }
    }

    if (!limitLow && !limitHigh) memo[i] = res;
    return res;
  };

  return dfs(0, true, true);
}
//sub: https://leetcode.com/problems/count-the-number-of-powerful-integers/submissions/1602571729/?envType=daily-question&envId=2025-04-10
//sol: https://leetcode.com/problems/count-the-number-of-powerful-integers/solutions/6636080/2999-count-the-number-of-powerful-intege-y4ye/
