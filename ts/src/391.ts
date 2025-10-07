//1488. Avoid Flood in The City
function avoidFlood(rains: number[]): number[] {
  const n = rains.length;
  const ans = new Array(n).fill(1);
  const full = new Map<number, number>(); // lake -> last rain day
  const dryDays = new Set<number>(); // available dry days (sorted manually)

  // Helper: get first dry day > target
  const findDryDay = (target: number): number | null => {
    for (const day of dryDays) {
      if (day > target) return day;
    }
    return null;
  };

  for (let i = 0; i < n; i++) {
    const lake = rains[i];

    if (lake > 0) {
      ans[i] = -1;

      if (full.has(lake)) {
        const prev = full.get(lake)!;
        const dryDay = findDryDay(prev);
        if (dryDay === null) return [];

        ans[dryDay] = lake;
        dryDays.delete(dryDay);
      }

      full.set(lake, i);
    } else {
      dryDays.add(i);
    }
  }

  return ans;
}
//sub: https://leetcode.com/problems/avoid-flood-in-the-city/submissions/1794016838/?envType=daily-question&envId=2025-10-07
//sol: https://leetcode.com/problems/avoid-flood-in-the-city/solutions/7255759/1488-avoid-flood-in-the-city-by-nalindal-emys/
