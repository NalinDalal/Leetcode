//3479. Fruits Into Baskets III
use std::cmp::{max, min};

impl Solution {
    pub fn num_of_unplaced_fruits(fruits: Vec<i32>, mut baskets: Vec<i32>) -> i32 {
        let n = baskets.len();
        let block_size = (n as f64).sqrt() as usize + 1;
        let num_blocks = (n + block_size - 1) / block_size;
        let mut max_v = vec![0; num_blocks];

        // Precompute max for each block
        for i in 0..n {
            let block = i / block_size;
            max_v[block] = max(max_v[block], baskets[i]);
        }

        let mut unplaced = 0;

        for fruit in fruits {
            let mut placed = false;

            for b in 0..num_blocks {
                if max_v[b] < fruit {
                    continue;
                }

                let start = b * block_size;
                let end = min(n, start + block_size);

                for i in start..end {
                    if baskets[i] >= fruit {
                        baskets[i] = 0;

                        // Recompute block max
                        max_v[b] = 0;
                        for j in start..end {
                            max_v[b] = max(max_v[b], baskets[j]);
                        }

                        placed = true;
                        break;
                    }
                }

                if placed {
                    break;
                }
            }

            if !placed {
                unplaced += 1;
            }
        }

        unplaced
    }
}

//sub: https://leetcode.com/problems/fruits-into-baskets-iii/submissions/1725704776/?envType=daily-question&envId=2025-08-06
//sol: https://leetcode.com/problems/fruits-into-baskets-iii/solutions/7051367/3479-fruits-into-baskets-iii-by-nalindal-wstg/
