//3208. Alternating Groups II

function numberOfAlternatingGroups(colors: number[], k: number): number {
  const n = colors.length,
    sz = n + k - 1;
  let ans = 0,
    alt = 1,
    prev = colors[0];

  for (let i = 1; i < sz; i++) {
    alt = prev === colors[i % n] ? 1 : alt + 1;
    if (alt >= k) ans++;
    prev = colors[i % n];
  }

  return ans;
}

// Example usage
console.log(numberOfAlternatingGroups([0, 1, 0, 1, 0], 3)); // Output: 5

//sub: https://leetcode.com/problems/alternating-groups-ii/submissions/1568066565/?envType=daily-question&envId=2025-03-09
//sol: https://leetcode.com/problems/alternating-groups-ii/solutions/6517274/3208-alternating-groups-ii-by-nalindalal-qqe4/
