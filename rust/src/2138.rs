//2138. Divide a String Into Groups of Size k
impl Solution {
    pub fn divide_string(s: String, k: i32, fill: char) -> Vec<String> {
        let mut result = Vec::new();
        let k = k as usize; // Convert i32 to usize for indexing
        let chars: Vec<char> = s.chars().collect();
        let mut i = 0;

        while i < chars.len() {
            let mut chunk: Vec<char> = chars[i..(i + k).min(chars.len())].to_vec();

            while chunk.len() < k {
                chunk.push(fill);
            }

            result.push(chunk.iter().collect());
            i += k;
        }

        result
    }
}

//sub: https://leetcode.com/problems/divide-a-string-into-groups-of-size-k/submissions/1672234152/
//sol: https://leetcode.com/problems/divide-a-string-into-groups-of-size-k/solutions/6870831/2138-divide-a-string-into-groups-of-size-k/
