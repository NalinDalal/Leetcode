//3443. Maximum Manhattan Distance After K Changes
function maxDistance(s: string, k: number): number {
  let ans = 0;
  let north = 0,
    south = 0,
    east = 0,
    west = 0;
  for (const it of s) {
    switch (it) {
      case "N":
        north++;
        break;
      case "S":
        south++;
        break;
      case "E":
        east++;
        break;
      case "W":
        west++;
        break;
    }
    const times1 = Math.min(north, south, k); // modification times for N and S
    const times2 = Math.min(east, west, k - times1); // modification times for E and W
    const current = count(north, south, times1) + count(east, west, times2);
    ans = Math.max(ans, current);
  }
  return ans;
}

function count(drt1: number, drt2: number, times: number): number {
  return Math.abs(drt1 - drt2) + times * 2;
} // Calculate modified Manhattan distance
//sub: https://leetcode.com/problems/maximum-manhattan-distance-after-k-changes/submissions/1670771446/?envType=daily-question&envId=2025-06-20
//sol: https://leetcode.com/problems/maximum-manhattan-distance-after-k-changes/solutions/6866400/3443-maximum-manhattan-distance-after-k-0p1xk/
