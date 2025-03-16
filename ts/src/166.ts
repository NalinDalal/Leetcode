//2594. Minimum Time to Repair Cars
function repairCars(ranks: number[], cars: number): number {
  let low: number = 1,
    high: number = ranks[0] * cars * cars;
  let ans = high;

  while (low <= high) {
    let mid = Math.floor(low + (high - low) / 2);
    if (canRepairAll(ranks, cars, mid)) {
      ans = mid; // Update answer with the valid time
      high = mid - 1; // Try a smaller time
    } else {
      low = mid + 1; // Increase time
    }
  }

  return ans;
}

function canRepairAll(ranks: number[], cars: number, time: number): boolean {
  let repaired = 0;

  for (let r of ranks) {
    let maxCars = Math.floor(Math.sqrt(time / r)); // Using the formula n = sqrt(T / r)
    repaired += maxCars;
    if (repaired >= cars) return true; // Early stopping
  }

  return repaired >= cars;
}

//sub: https://leetcode.com/problems/minimum-time-to-repair-cars/submissions/1575422675/?envType=daily-question&envId=2025-03-16
//sol: https://leetcode.com/problems/minimum-time-to-repair-cars/solutions/6542152/2594-minimum-time-to-repair-cars-by-nali-y13f/
