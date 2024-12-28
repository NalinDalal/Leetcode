//1014. Best Sightseeing Pair
function maxScoreSightseeingPair(values: number[]): number {
  let ans: number = 0;
  let a: number = values[0];
  for (let i: number = 1; i < values.length; i++) {
    a--;
    let b: number = values[i];
    ans = Math.max(ans, a + b);
    a = Math.max(a, b);
  }
  return ans;
}
