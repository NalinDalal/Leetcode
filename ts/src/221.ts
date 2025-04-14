//1534. Count Good Triplets

function countGoodTriplets(
  arr: number[],
  a: number,
  b: number,
  c: number,
): number {
  let count = 0;

  for (let i = 0; i < arr.length - 2; i++) {
    for (let j = i + 1; j < arr.length - 1; j++) {
      if (Math.abs(arr[i] - arr[j]) <= a) {
        for (let k = j + 1; k < arr.length; k++) {
          if (
            Math.abs(arr[j] - arr[k]) <= b &&
            Math.abs(arr[i] - arr[k]) <= c
          ) {
            count++;
          }
        }
      }
    }
  }

  return count;
}
//sub: https://leetcode.com/problems/count-good-triplets/submissions/1606139076/?envType=daily-question&envId=2025-04-14
//sol:https://leetcode.com/problems/count-good-triplets/solutions/6648385/1534-count-good-triplets-by-nalindalal20-fm4i/
