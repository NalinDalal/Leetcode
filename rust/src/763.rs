//763. Partition Labels
impl Solution {
    pub fn partition_labels(s: String) -> Vec<i32> {
        let mut last_index = vec![0; 26];
        let mut result = Vec::new();

        // Step 1: Store last occurrence of each character
        for (i, c) in s.chars().enumerate() {
            last_index[(c as u8 - b'a') as usize] = i;
        }

        // Step 2: Traverse and partition
        let (mut start, mut end) = (0, 0);
        for (i, c) in s.chars().enumerate() {
            end = end.max(last_index[(c as u8 - b'a') as usize]);

            if i == end {
                result.push((end - start + 1) as i32);
                start = i + 1;
            }
        }

        result
    }
}

// Example usage
fn main() {
    let s = "ababcbacadefegdehijhklij".to_string();
    println!("{:?}", Solution::partition_labels(s)); // Output: [9, 7, 8]
}

//sub: https://leetcode.com/problems/partition-labels/submissions/1568045663/
//sol: https://leetcode.com/problems/partition-labels/solutions/6517178/763-partition-labels-by-nalindalal2004-98is/
