//3495. Minimum Operations to Make Array Elements Zero
function minOperations(queries: number[][]): number {
  let TO = 0;

  for (const query of queries) {
    let [l, r] = query;
    let ops = 0;

    let max_ops = r > 0 ? Math.floor(Math.log(r) / Math.log(4)) + 1 : 0;

    for (let k = 0; k <= max_ops; k++) {
      let lower = Math.pow(4, k);
      let upper = Math.pow(4, k + 1) - 1;

      lower = Math.max(lower, l);
      upper = Math.min(upper, r);

      if (lower <= upper) {
        let count = upper - lower + 1;
        ops += count * (k + 1);
      }
    }
    TO += Math.floor((ops + 1) / 2);
  }

  return TO;
}
//sub: https://leetcode.com/problems/minimum-operations-to-make-array-elements-zero/submissions/1761081510/?envType=daily-question&envId=2025-09-06
//sol: https://leetcode.com/problems/minimum-operations-to-make-array-elements-zero/solutions/7160126/3495-minimum-operations-to-make-array-el-yvh5/
