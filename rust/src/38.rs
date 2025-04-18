//38. Count and Say

impl Solution {
    pub fn count_and_say(n: i32) -> String {
        if n == 1 {
            return "1".to_string();
        }

        let prev = Solution::count_and_say(n - 1);
        let chars: Vec<char> = prev.chars().collect();
        let mut result = String::new();
        let mut count = 1;

        for i in 1..=chars.len() {
            if i < chars.len() && chars[i] == chars[i - 1] {
                count += 1;
            } else {
                result.push_str(&count.to_string());
                result.push(chars[i - 1]);
                count = 1;
            }
        }

        result
    }
}
//sub: https://leetcode.com/problems/count-and-say/submissions/1610132528/?envType=daily-question&envId=2025-04-18
//sol: https://leetcode.com/problems/count-and-say/solutions/6662271/38-count-and-say-by-nalindalal2004-tqmx/
