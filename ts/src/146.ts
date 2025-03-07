//2965. Find Missing and Repeated Values
//linear search, with hashmap, increase count with each instances of i
//return count element>1 and no which is not present
function findErrorNums(grid: number[][]): number[] {
  const n = grid.length;
  const count = new Map<number, number>();
  const maxNum = n * n;

  // Count occurrences of each number
  for (const row of grid) {
    for (const num of row) {
      count.set(num, (count.get(num) || 0) + 1);
    }
  }

  let repeated = -1,
    missing = -1;

  // Find repeated and missing numbers
  for (let i = 1; i <= maxNum; i++) {
    if (!count.has(i)) missing = i;
    if (count.get(i) === 2) repeated = i;
  }

  return [repeated, missing];
}
//sub: https://leetcode.com/problems/find-missing-and-repeated-values/submissions/1564596003/
