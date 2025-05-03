//1007. Minimum Domino Rotations For Equal Row
impl Solution {
    pub fn check(target: i32, tops: &Vec<i32>, bottoms: &Vec<i32>) -> i32 {
        let mut rotations_top = 0;
        let mut rotations_bottom = 0;
        let n = tops.len();

        for i in 0..n {
            if tops[i] != target && bottoms[i] != target {
                return -1; // Cannot make all values equal to target
            } else if tops[i] != target {
                rotations_top += 1;
            } else if bottoms[i] != target {
                rotations_bottom += 1;
            }
        }

        rotations_top.min(rotations_bottom)
    }

    pub fn min_domino_rotations(tops: Vec<i32>, bottoms: Vec<i32>) -> i32 {
        let res1 = Self::check(tops[0], &tops, &bottoms);
        if res1 != -1 {
            return res1;
        }

        if tops[0] != bottoms[0] {
            let res2 = Self::check(bottoms[0], &tops, &bottoms);
            return res2;
        }

        -1
    }
}
//sub: https://leetcode.com/problems/minimum-domino-rotations-for-equal-row/submissions/1624042359/?envType=daily-question&envId=2025-05-03
