//3394. Check if Grid can be Cut into Sections
struct Solution;

impl Solution {
    pub fn check_valid_cuts(n: i32, rectangles: Vec<Vec<i32>>) -> bool {
        Solution::check_cuts(&rectangles, 0) || Solution::check_cuts(&rectangles, 1)
    }

    fn check_cuts(rectangles: &Vec<Vec<i32>>, dim: usize) -> bool {
        let mut rectangles = rectangles.clone();
        rectangles.sort_by_key(|rect| rect[dim]);

        let mut gap_count = 0;
        let mut furthest_end = rectangles[0][dim + 2];

        for rect in &rectangles[1..] {
            if furthest_end <= rect[dim] {
                gap_count += 1;
            }

            furthest_end = furthest_end.max(rect[dim + 2]);
        }

        gap_count >= 2
    }
}
//sub:https://leetcode.com/problems/check-if-grid-can-be-cut-into-sections/submissions/1585385416/?envType=daily-question&envId=2025-03-25
//sol:https://leetcode.com/problems/check-if-grid-can-be-cut-into-sections/solutions/6577093/3394-check-if-grid-can-be-cut-into-secti-jkra/
