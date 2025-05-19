//3024. Type of Triangle
impl Solution {
    pub fn triangle_type(mut nums: Vec<i32>) -> String {
        nums.sort();
        let (a, b, c) = (nums[0], nums[1], nums[2]);

        if a + b <= c {
            return "none".to_string();
        }

        if a == b && b == c {
            "equilateral".to_string()
        } else if a == b || b == c || a == c {
            "isosceles".to_string()
        } else {
            "scalene".to_string()
        }
    }
}

//sub:https://leetcode.com/problems/type-of-triangle/submissions/1637718866/?envType=daily-question&envId=2025-05-19
