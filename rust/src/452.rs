//452. Minimum Number of Arrows to Burst Balloons
impl Solution {
    pub fn find_min_arrow_shots(mut points: Vec<Vec<i32>>) -> i32 {
        if points.is_empty() {
            return 0;
        }

        // Sort by end coordinate
        points.sort_by_key(|interval| interval[1]);

        let mut arrows = 1;
        let mut end = points[0][1];

        for point in points.iter().skip(1) {
            if point[0] > end {
                arrows += 1;
                end = point[1];
            }
        }

        arrows
    }

    pub fn overlap_group_count(points: Vec<Vec<i32>>) -> i32 {
        let total = points.len() as i32;
        let arrows = Self::find_min_arrow_shots(points);
        total - arrows
    }
}
//sub: https://leetcode.com/problems/minimum-number-of-arrows-to-burst-balloons/submissions/1602555535/?envType=study-plan-v2&envId=top-interview-150
//sol: https://leetcode.com/problems/minimum-number-of-arrows-to-burst-balloons/solutions/6636009/452-minimum-number-of-arrows-to-burst-ba-9inp/
