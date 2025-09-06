//3495. Minimum Operations to Make Array Elements Zero
impl Solution {
    pub fn min_operations(queries: Vec<Vec<i32>>) -> i64 {
        let mut to = 0i64;

        for query in queries {
            let l = query[0];
            let r = query[1];
            let mut ops = 0i64;

            let max_ops = if r > 0 {
                ( (r as f64).log(4.0).floor() as i64 ) + 1
            } else {
                0
            };

            for k in 0..=max_ops {
                let mut lower = 4i64.pow(k as u32);
                let mut upper = 4i64.pow((k + 1) as u32) - 1;

                lower = lower.max(l.into());
                upper = upper.min(r.into());

                if lower <= upper {
                    let count = upper - lower + 1;
                    ops += count * (k + 1);
                }
            }
            to += (ops + 1) / 2;
        }

        to
    }
}
//sub: https://leetcode.com/problems/minimum-operations-to-make-array-elements-zero/submissions/1761082922/?envType=daily-question&envId=2025-09-06
//sol: https://leetcode.com/problems/minimum-operations-to-make-array-elements-zero/solutions/7160126/3495-minimum-operations-to-make-array-el-yvh5/
