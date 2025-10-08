//2300. Successful Pairs of Spells and Potions
impl Solution {
    pub fn successful_pairs(spells: Vec<i32>, mut potions: Vec<i32>, success: i64) -> Vec<i32> {
        potions.sort();
        let m = potions.len();
        let mut res = Vec::with_capacity(spells.len());

        for &spell in &spells {
            // Compute minimum potion needed for success
            let min_potion = ((success + spell as i64 - 1) / spell as i64) as i64;

            // Binary search for the first potion >= min_potion
            let mut left = 0;
            let mut right = m;

            while left < right {
                let mid = left + (right - left) / 2;
                if potions[mid] as i64 >= min_potion {
                    right = mid;
                } else {
                    left = mid + 1;
                }
            }

            // Count of successful pairs for this spell
            res.push((m - left) as i32);
        }

        res
    }
}

//sub: https://leetcode.com/problems/successful-pairs-of-spells-and-potions/submissions/1794951368/?envType=daily-question&envId=2025-10-08
//sol: https://leetcode.com/problems/successful-pairs-of-spells-and-potions/solutions/7258068/2300-successful-pairs-of-spells-and-poti-uewb/
