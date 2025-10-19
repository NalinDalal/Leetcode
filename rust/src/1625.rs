//1625. Lexicographically Smallest String After Applying Operations
use std::collections::{HashSet, VecDeque};

impl Solution {
    pub fn find_lex_smallest_string(s: String, a: i32, b: i32) -> String {
        let mut seen = HashSet::new();
        let mut queue = VecDeque::new();
        let mut smallest = s.clone();

        queue.push_back(s.clone());
        seen.insert(s.clone());

        while let Some(cur) = queue.pop_front() {
            if cur < smallest {
                smallest = cur.clone();
            }

            // Operation 1: add 'a' to all digits at odd indices
            let mut chars: Vec<char> = cur.chars().collect();
            for i in (1..chars.len()).step_by(2) {
                let digit = (chars[i].to_digit(10).unwrap() + a as u32) % 10;
                chars[i] = std::char::from_digit(digit, 10).unwrap();
            }
            let add_op: String = chars.iter().collect();

            if seen.insert(add_op.clone()) {
                queue.push_back(add_op);
            }

            // Operation 2: rotate right by b positions
            let n = cur.len();
            let rb = b as usize % n;
            let rotate_op = format!("{}{}", &cur[n - rb..], &cur[..n - rb]);

            if seen.insert(rotate_op.clone()) {
                queue.push_back(rotate_op);
            }
        }

        smallest
    }
}

//sub: https://leetcode.com/problems/lexicographically-smallest-string-after-applying-operations/submissions/1805803053/?envType=daily-question&envId=2025-10-19
//sol: https://leetcode.com/problems/lexicographically-smallest-string-after-applying-operations/solutions/7285898/1625-lexicographically-smallest-string-a-3fvv/
