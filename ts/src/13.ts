// 983. Minimum Cost For Tickets

function mincostTickets(days: number[], costs: number[]): number {
  const n = days.length;
  const dp: number[] = Array(days[n - 1] + 1).fill(0); // Minimum cost up to day i
  const travelDays = new Set(days); // To check if a day is a travel day in O(1)

  for (let i = 1; i <= days[n - 1]; i++) {
    if (!travelDays.has(i)) {
      dp[i] = dp[i - 1]; // No travel on this day
    } else {
      dp[i] = Math.min(
        dp[Math.max(0, i - 1)] + costs[0], // 1-day pass
        dp[Math.max(0, i - 7)] + costs[1], // 7-day pass
        dp[Math.max(0, i - 30)] + costs[2], // 30-day pass
      );
    }
  }

  return dp[days[n - 1]];
}
