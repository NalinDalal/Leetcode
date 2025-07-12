//1900. The Earliest and Latest Rounds Where Players Compete
use std::collections::HashMap;

impl Solution {
    pub fn earliest_and_latest(n: i32, first_player: i32, second_player: i32) -> Vec<i32> {
        fn dfs(
            n: i32,
            a: i32,
            b: i32,
            memo: &mut HashMap<(i32, i32, i32), (i32, i32)>,
        ) -> (i32, i32) {
            let (a, b) = if a > b { (b, a) } else { (a, b) };
            if a + b == n + 1 {
                return (1, 1);
            }

            if let Some(&res) = memo.get(&(n, a, b)) {
                return res;
            }

            let mut min_round = i32::MAX;
            let mut max_round = i32::MIN;

            let half = n / 2;
            let total_comb = 1 << half;

            for mask in 0..total_comb {
                let mut next = vec![];
                let mut alive_a = false;
                let mut alive_b = false;

                for i in 1..=half {
                    let left = i;
                    let right = n - i + 1;
                    let winner = if (mask & (1 << (i - 1))) > 0 {
                        left
                    } else {
                        right
                    };
                    if winner == a {
                        alive_a = true;
                    }
                    if winner == b {
                        alive_b = true;
                    }
                    next.push(winner);
                }

                if n % 2 == 1 {
                    let mid = n / 2 + 1;
                    next.push(mid);
                    if mid == a {
                        alive_a = true;
                    }
                    if mid == b {
                        alive_b = true;
                    }
                }

                if !alive_a || !alive_b {
                    continue;
                }

                next.sort();
                let new_a = (next.iter().position(|&x| x == a).unwrap() + 1) as i32;
                let new_b = (next.iter().position(|&x| x == b).unwrap() + 1) as i32;

                let (earliest, latest) = dfs(next.len() as i32, new_a, new_b, memo);
                min_round = min_round.min(1 + earliest);
                max_round = max_round.max(1 + latest);
            }

            memo.insert((n, a, b), (min_round, max_round));
            (min_round, max_round)
        }

        let mut memo = HashMap::new();
        let (min_r, max_r) = dfs(n, first_player, second_player, &mut memo);
        vec![min_r, max_r]
    }
}

//sub: https://leetcode.com/problems/the-earliest-and-latest-rounds-where-players-compete/submissions/1695459974/?envType=daily-question&envId=2025-07-12
//sol: https://leetcode.com/problems/the-earliest-and-latest-rounds-where-players-compete/solutions/6950405/1900-the-earliest-and-latest-rounds-wher-knph/
