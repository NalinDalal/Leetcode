//2226. Maximum Candies Allocated to K Children
function maximumCandies(candies: number[], k: number): number {
  function canDistribute(c: number): boolean {
    let count = 0;
    for (let num of candies) {
      count += Math.floor(num / c);
    }
    return count >= k;
  }

  let low = 1,
    high = Math.max(...candies),
    result = 0;

  while (low <= high) {
    let mid = Math.floor(low + (high - low) / 2);
    if (canDistribute(mid)) {
      result = mid; // Store valid c
      low = mid + 1; // Try a larger c
    } else {
      high = mid - 1; // Try a smaller c
    }
  }

  return result;
}

// Example Usage:
console.log(maximumCandies([5, 8, 6], 3)); // Output: 5
//sub: https://leetcode.com/problems/maximum-candies-allocated-to-k-children/submissions/1573379873/?envType=daily-question&envId=2025-03-14
//sol: https://leetcode.com/problems/maximum-candies-allocated-to-k-children/solutions/6535464/2226-maximum-candies-allocated-to-k-chil-k06e/
