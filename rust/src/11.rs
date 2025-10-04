//11.Container With Most Water
impl Solution {
    pub fn max_area(height: Vec<i32>) -> i32 {
        let mut i = 0;
        let mut j = height.len() - 1;
        let mut res = 0;

        while i < j {
            let h = std::cmp::min(height[i], height[j]);
            let area = h * (j - i) as i32;
            res = std::cmp::max(res, area);

            if height[i] < height[j] {
                i += 1;
            } else {
                j -= 1;
            }
        }

        res
    }
}
//sub: https://leetcode.com/problems/container-with-most-water/submissions/1790927364/?envType=daily-question&envId=2025-10-04
//sol: https://leetcode.com/problems/container-with-most-water/solutions/7247604/11-container-with-most-water-by-nalindal-s9o2/
