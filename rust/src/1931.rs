//1931. Painting a Grid With Three Different Colors

use std::collections::HashMap;

const MOD: i32 = 1_000_000_007;

impl Solution {
    pub fn color_the_grid(m: i32, n: i32) -> i32 {
        let m = m as usize;
        let n = n as usize;
        // Hash mapping stores all valid coloration schemes for a single row that meet the requirements
        let mut valid = HashMap::new();
        // Enumerate masks that meet the requirements within the range [0, 3^m)
        let mask_end = 3i32.pow(m as u32);
        for mask in 0..mask_end {
            let mut color = Vec::new();
            let mut mm = mask;
            for _ in 0..m {
                color.push(mm % 3);
                mm /= 3;
            }
            let mut check = true;
            for i in 0..m - 1 {
                if color[i] == color[i + 1] {
                    check = false;
                    break;
                }
            }
            if check {
                valid.insert(mask, color);
            }
        }

        // Preprocess all (mask1, mask2) binary tuples, satisfying mask1 and mask2 When adjacent rows, the colors of the two cells in the same column are different
        let mut adjacent = HashMap::new();
        for (&mask1, color1) in &valid {
            for (&mask2, color2) in &valid {
                let mut check = true;
                for i in 0..m {
                    if color1[i] == color2[i] {
                        check = false;
                        break;
                    }
                }
                if check {
                    adjacent.entry(mask1).or_insert(Vec::new()).push(mask2);
                }
            }
        }

        let mut f = HashMap::new();
        for &mask in valid.keys() {
            f.insert(mask, 1);
        }
        for _ in 1..n {
            let mut g = HashMap::new();
            for &mask2 in valid.keys() {
                let mut total = 0;
                if let Some(list) = adjacent.get(&mask2) {
                    for &mask1 in list {
                        total = (total + f.get(&mask1).unwrap_or(&0)) % MOD;
                    }
                }
                g.insert(mask2, total);
            }
            f = g;
        }

        let mut ans = 0;
        for &num in f.values() {
            ans = (ans + num) % MOD;
        }
        ans
    }
}
//sub: https://leetcode.com/problems/painting-a-grid-with-three-different-colors/submissions/1637071221/?envType=daily-question&envId=2025-05-18
