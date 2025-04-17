//909. Snakes and Ladders

use std::collections::VecDeque;
impl Solution {
    pub fn snakes_and_ladders(board: Vec<Vec<i32>>) -> i32 {
        let n = board.len();
        let mut mboard = vec![];

        // Flatten the board
        for (i, row) in board.iter().rev().enumerate() {
            if i % 2 == 0 {
                mboard.extend(row.iter().cloned());
            } else {
                mboard.extend(row.iter().rev().cloned());
            }
        }

        let mut best = vec![None; n * n];
        let mut queue = VecDeque::new();
        queue.push_back(0);
        best[0] = Some(0);

        while let Some(current) = queue.pop_front() {
            for i in 1..=6 {
                let mut next = current + i;
                if next >= n * n {
                    continue;
                }

                if mboard[next] != -1 {
                    next = (mboard[next] - 1) as usize;
                }

                if next == n * n - 1 {
                    return best[current].unwrap() + 1;
                }

                if best[next].is_none() {
                    best[next] = Some(best[current].unwrap() + 1);
                    queue.push_back(next);
                }
            }
        }

        -1
    }
}
//sub: https://leetcode.com/problems/snakes-and-ladders/submissions/1609171215/?envType=study-plan-v2&envId=top-interview-150
//sol: https://leetcode.com/problems/snakes-and-ladders/solutions/6658694/909-snakes-and-ladders-by-nalindalal2004-yi7i/
