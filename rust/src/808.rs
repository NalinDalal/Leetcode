//808. Soup Servings
use std::collections::HashMap;

impl Solution {
    pub fn soup_servings(n: i32) -> f64 {
        if n >= 4800 {
            return 1.0;
        }
        let n = (n + 24) / 25;
        let mut memo = HashMap::new();
        Self::dfs(n, n, &mut memo)
    }

    fn dfs(a: i32, b: i32, memo: &mut HashMap<(i32, i32), f64>) -> f64 {
        if a <= 0 && b <= 0 {
            return 0.5;
        }
        if a <= 0 {
            return 1.0;
        }
        if b <= 0 {
            return 0.0;
        }
        if let Some(&val) = memo.get(&(a, b)) {
            return val;
        }

        let res = 0.25 * (
            Self::dfs((a - 4).max(0), b, memo)
            + Self::dfs((a - 3).max(0), (b - 1).max(0), memo)
            + Self::dfs((a - 2).max(0), (b - 2).max(0), memo)
            + Self::dfs((a - 1).max(0), (b - 3).max(0), memo)
        );

        memo.insert((a, b), res);
        res
    }
}

// Required for testing
struct Solution;

fn main() {
    println!("{}", Solution::soup_servings(50));   // 0.625
    println!("{}", Solution::soup_servings(100));  // 0.71875
}

//sub: https://leetcode.com/problems/soup-servings/submissions/1727554783/
//sol: https://leetcode.com/problems/soup-servings/solutions/7056532/808-soup-servings-by-nalindalal2004-ylkh/
