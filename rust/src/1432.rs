//1432. Max Difference You Can Get From Changing an Integer
impl Solution {
    pub fn max_diff(num: i32) -> i32 {
        let s = num.to_string();

        // Maximize
        let mut max_s: Vec<char> = s.chars().collect();
        let mut to_replace = None;

        for &c in &max_s {
            if c != '9' {
                to_replace = Some(c);
                break;
            }
        }

        if let Some(ch) = to_replace {
            for c in &mut max_s {
                if *c == ch {
                    *c = '9';
                }
            }
        }

        let a: i32 = max_s.iter().collect::<String>().parse().unwrap();

        // Minimize
        let mut min_s: Vec<char> = s.chars().collect();
        to_replace = None;

        if min_s[0] != '1' {
            to_replace = Some(min_s[0]);
            for c in &mut min_s {
                if *c == to_replace.unwrap() {
                    *c = '1';
                }
            }
        } else {
            for i in 1..min_s.len() {
                if min_s[i] != '0' && min_s[i] != '1' {
                    to_replace = Some(min_s[i]);
                    break;
                }
            }

            if let Some(ch) = to_replace {
                for c in &mut min_s {
                    if *c == ch {
                        *c = '0';
                    }
                }
            }
        }

        let b: i32 = min_s.iter().collect::<String>().parse().unwrap();

        a - b
    }
}

//sub: https://leetcode.com/problems/max-difference-you-can-get-from-changing-an-integer/submissions/1664536849/?envType=daily-question&envId=2025-06-15
//sol: https://leetcode.com/problems/max-difference-you-can-get-from-changing-an-integer/solutions/6844775/1432-max-difference-you-can-get-from-cha-8swi/
