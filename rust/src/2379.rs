//2379. Minimum Recolors to Get K Consecutive Black Blocks

impl Solution {
    pub fn minimum_recolors(blocks: String, k: i32) -> i32 {
        let n = blocks.len();
        let chars: Vec<char> = blocks.chars().collect();
        let mut min_operations = i32::MAX;

        // Iterate through the string with a sliding window of size k
        for i in 0..=(n as i32 - k) {
            let mut white_count = 0;

            // Count the number of 'W's in the current window
            for j in i..i + k {
                if chars[j as usize] == 'W' {
                    white_count += 1;
                }
            }

            // Update the minimum number of operations
            min_operations = min_operations.min(white_count);
        }

        min_operations
    }
}

// Example usage
fn main() {
    println!("{}", Solution::minimum_recolors("BWWBB".to_string(), 2)); // Output: 1
}
//sub:https://leetcode.com/problems/minimum-recolors-to-get-k-consecutive-black-blocks/submissions/1566748446/?envType=daily-question&envId=2025-03-08
//sol: https://leetcode.com/problems/minimum-recolors-to-get-k-consecutive-black-blocks/solutions/6512261/2379-minimum-recolors-to-get-k-consecuti-u3z6/
